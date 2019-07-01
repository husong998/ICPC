#include<bits/stdc++.h>
using namespace std;

const int maxn = 200010;
vector<int> adj[maxn];
int n;
long long dp[maxn], ans;
int cntnode[maxn];

void dfs(int u, int fa, int d) {
  dp[u] += d;
  ++cntnode[u];
  for (auto v : adj[u]) {
    if (v != fa) {
      dfs(v, u, d + 1);
      dp[u] += dp[v];
      cntnode[u] += cntnode[v];
    }
  }
}

void dfs2(int u, int fa) {
  ans = max(ans, dp[u]);
  for (auto v : adj[u]) {
    if (v != fa) {
      dp[u] -= dp[v];
      cntnode[u] -= cntnode[v];
      dp[u] += cntnode[u];
      dp[v] -= cntnode[v];
      cntnode[v] += cntnode[u];
      dp[v] += dp[u];
      dfs2(v, u);

      dp[v] -= dp[u];
      cntnode[v] -= cntnode[u];
      dp[v] += cntnode[v];
      dp[u] -= cntnode[u];
      cntnode[u] += cntnode[v];
      dp[u] += dp[v];
    }
  }
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, - 1, 1);
  dfs2(0, -1);
  cout << ans;
  return 0;
}