#include<bits/stdc++.h>
using namespace std;

const int maxn = 20010;
const double eps = 1e-6;

struct endpoint {
  int x, isend, id;
  const bool operator < (const endpoint b) { return x < b.x; }
};

endpoint a[maxn];
double len[maxn];
int s[maxn], e[maxn], n, w[maxn];

bool check(int x) {
  auto cmp = [](int a, int b) { return e[a] > e[b]; };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  double last;
  // cout << "x: " << x << endl;
  for (int i = 0; i < 2 * n; ++i) {
    while (!pq.empty() && last < a[i].x - eps) {
      // cout << "(" << s[pq.top()] << ", " << e[pq.top()] << ")" << ' ';
      if (a[i].x - last > len[pq.top()]) {
        last += len[pq.top()];
        len[pq.top()] = 0;
        pq.pop();
      } else {
        len[pq.top()] -= a[i].x - last;
        last = a[i].x;
      }
    }
    // cout << endl;
    
    if (a[i].isend && len[a[i].id] > eps) return 0;
    if (!a[i].isend) pq.push(a[i].id);
    last = a[i].x;
  }
  return 1;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> s[i] >> e[i] >> w[i];
      a[i * 2] = (endpoint){s[i], 0, i};
      a[i * 2 + 1] = (endpoint){e[i], 1, i};
    }
    sort(a, a + n * 2);
    
    int L = 0, R = 10000000;
    while (R - L > 1) {
      int M = (R + L) / 2;
      for (int i = 0; i < n; ++i) len[i] = w[i] * 1.0 / M;
      // for (int i = 0; i < n; ++i) cout << len[i] << ' '; cout << endl;
      if (check(M)) R = M;
      else L = M;
    }
    
    cout << R << endl;
  }
  return 0;
}