#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef pair<int, int> pii;

const int maxn = 2010, INF = 0x3f3f3f3f;
int a[maxn], val[maxn], dp[maxn][maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  memcpy(val, a, sizeof a);
  sort(val, val + n);
  for (int i = 0; i < n; ++i) dp[0][i] = abs(a[0] - val[i]);
  for (int i = 0; i < n - 1; ++i) {
    int mmin = INF;
    for (int j = 0; j < n; ++j) {
      mmin = min(mmin, dp[i][j]);
      dp[i + 1][j] = mmin + abs(val[j] - a[i + 1]);
    }
  }
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; ++i) ans = min(ans, dp[n - 1][i]);
  cout << ans;
  return 0;
}