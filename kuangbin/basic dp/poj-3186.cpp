#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn = 2010;
long long a[maxn], dp[maxn][maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  memset(dp, 0, sizeof dp);
  dp[0][n] = 0;
  for (int k = n; k; --k) {
    for (int j = 0; j + k <= n; ++j) {
      dp[j][j + k - 1] = max(dp[j][j + k - 1], dp[j][j + k] + (n - k + 1) * a[j + k - 1]);
      dp[j + 1][j + k] = max(dp[j][j + k], dp[j][j + k] + (n - k + 1) * a[j]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, dp[i][i]);
  cout << ans;
  return 0;
}