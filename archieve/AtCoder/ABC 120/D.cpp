#include<bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 100010;
int u[N], v[N], fa[N], sz[N];
long long ans[N];

int find(int cur) { return fa[cur] == cur ? cur : fa[cur] = find(fa[cur]); }

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int vn, en;
  cin >> vn >> en;
  for (int i = 0; i < en; ++i) {
    scanf("%d%d", &u[i], &v[i]);
    --u[i]; --v[i];
  }
  for (int i = 0; i < vn; ++i) {
    fa[i] = i;
    sz[i] = 1;
  }

  ans[en] = (long long) vn * (vn - 1) / 2;
  for (int i = en - 1; i >= 0; --i) {
    long long connected;
    int rtu = find(u[i]), rtv = find(v[i]);
    // cerr << "node " << u[i] << " , size " << sz[rtu] << "...." 
    //  << "node " << v[i] << " , size " << sz[rtv] << '\n';
    if (rtu == rtv) connected = 0;
    else {
      connected = (long long) sz[rtu] * sz[rtv];
      fa[rtu] = rtv;
      sz[rtv] += sz[rtu];
    }
    ans[i] = ans[i + 1] - connected;
  }
  for (int i = 1; i <= en; ++i) cout << ans[i] << '\n';
  return 0;
}
