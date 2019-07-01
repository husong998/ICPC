#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010, M = 2000;
int n, m;
vector<int> adj[maxn];

int dp(int i, int j) {
  if (adj[i].size() == 1) {
  }
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    memset(vis, 0, sizeof vis);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        int r = dfs(i, -1);
        int ans = dp(r, 0);
        a += asn / M;
        b += asn % M;
        c += m - asn % M;
      }
    }
    cout << a << ' ' << b << ' ' << c << endl;
  }
  return 0;
}