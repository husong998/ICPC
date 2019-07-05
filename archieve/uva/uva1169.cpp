#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010, INF = 0X3f3f3f3f;
int dp[maxn][110], x[maxn], y[maxn], w[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int k = 0; k < tc; ++k) {
    memset(dp, INF, sizeof dp);
    int n, c;
    cin >> c >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> w[i];
    dp[0][0] = 0;

    int ans = INF;
    for (int i = 1; i <= n; ++i) {
      for (int j = w[i]; j <= c; ++j) dp[i][j] = min(dp[i][j], dp[i - 1][j - w[i]] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]));
      int Min = INF;
      for (int j = 0; j <= c; ++j) Min = min(Min, dp[i - 1][j]);
      dp[i][w[i]] = min(dp[i][w[i]], Min + abs(x[i]) + abs(y[i]) + abs(x[i - 1]) + abs(y[i - 1]));
    }

    for (int i = 0; i <= c; ++i) ans = min(ans, dp[n][i]);
    if (k) cout << endl;
    cout << ans + abs(x[n]) + abs(y[n]) << endl;
  }
  return 0;
}