#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010, M = 2000;
vector<int> adj[maxn];
int memo[maxn][2];

int dp(int u, int fa, int fl) {
  if (adj[u].size() == 1) return memo[u][fl] = (fl ? M : 0);
  if (memo[u][fl] != -1) return memo[u][fl];
  if (fl) {
    memo[u][fl] = M;
    for (auto v : adj[u]) {
      if (v != fa) {
        memo[u][fl] += min(dp(v, u, 0) + 1, dp(v, u, 1));
      }
    }
  } else {
    memo[u][fl] = 0;
    for (auto v : adj[u]) {
      if (v != fa) {
        memo[u][fl] += dp(v, u, 1) + 1;
      }
    }
  }
  return memo[u][fl];
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) adj[i].clear();
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int tot, n1;
    tot = n1 = 0;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < n; ++i) {
      if (!memo[i][0] && !memo[i][1]) {
        int cur = min(dp(i, -1, 0), dp(i, -1, 1));
        tot += cur / M;
        n1 += cur % M;
      }
    }
    cout << tot << ' ' << m - n1 << ' ' << n1 << endl;
  }
  return 0;
}