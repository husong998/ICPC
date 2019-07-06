#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int u[maxn], v[maxn], w[maxn], deg[maxn], vis[maxn];
vector<int> adj[maxn];
tuple<int, int, int> ans[100010];

int dfs(int u, int fa) {
  vis[u] = 1;
  for (auto v : adj[u]) if (!vis[v] && v != fa) return dfs(v, u);
  return u;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int n; 
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    --u[i]; --v[i];
    adj[u[i]].push_back(v[i]);
    adj[v[i]].push_back(u[i]);
    ++deg[u[i]]; ++deg[v[i]];
  }
  int ok = 1;
  for (int i = 0; i < n; ++i) if (deg[i] == 2) { ok = 0; break; }
  if (!ok) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if (n == 2) {
    cout << 1 << endl;
    cout << u[0] + 1 << ' ' << v[0] + 1 << ' ' << w[0] << endl;
    return 0;
  }
  int tot = 0;
  for (int i = 0; i < n - 1; ++i) {
    memset(vis, 0, sizeof vis);
    if (deg[u[i]] == 1) {
      int l1 = dfs(v[i], u[i]), l2 = dfs(v[i], u[i]);
      ans[tot++] = make_tuple(u[i], l1, w[i] >> 1);
      ans[tot++] = make_tuple(u[i], l2, w[i] >> 1);
      ans[tot++] = make_tuple(l1, l2, -w[i] >> 1);
    } else if (deg[v[i]] == 1) {
      int l1 = dfs(u[i], v[i]), l2 = dfs(u[i], v[i]);
      ans[tot++] = make_tuple(v[i], l1, w[i] >> 1);
      ans[tot++] = make_tuple(v[i], l2, w[i] >> 1);
      ans[tot++] = make_tuple(l1, l2, -w[i] >> 1);
    } else {
      int l1 = dfs(v[i], u[i]);
      int l2 = dfs(v[i], u[i]);
      int l3 = dfs(u[i], v[i]);
      ans[tot++] = make_tuple(l3, l1, w[i] >> 1);
      ans[tot++] = make_tuple(l3, l2, w[i] >> 1);
      ans[tot++] = make_tuple(l2, l1, -w[i] >> 1);
      l1 = dfs(u[i], -1);
      ans[tot++] = make_tuple(l3, l1, -w[i] >> 1);
      ans[tot++] = make_tuple(l3, l2, -w[i] >> 1);
      ans[tot++] = make_tuple(l2, l1, w[i] >> 1);
    }
  }
  cout << tot << endl;
  for (int i = 0; i < tot; ++i) {
    int a, b, c;
    tie(a, b, c) = ans[i];
    ++a; ++b;
    cout << a << ' ' << b << ' ' << c << endl;
  }
  return 0;
}