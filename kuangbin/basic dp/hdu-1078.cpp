#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef pair<int, int> pii;

const int maxn = 110;
int mat[maxn][maxn], dp[maxn][maxn];
pii pos[maxn * maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  int n, k;
  while (scanf("%d%d", &n, &k), n >= 0) {
    int tot = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      scanf("%d", &mat[i][j]);
      if (i || j) pos[tot++] = make_pair(i, j);
    }
    sort(pos, pos + tot, [](pii a, pii b) {
      return mat[a.first][a.second] < mat[b.first][b.second];
    });
    memset(dp, -1, sizeof dp);
    dp[0][0] = mat[0][0];
    for (int i = 0; i < tot; ++i) {
      if (mat[pos[i].first][pos[i].second] <= mat[0][0]) continue;
      int lowi = max(pos[i].first - k, 0), highi = min(pos[i].first + k, n - 1);
      int lowj = max(pos[i].second - k, 0), highj = min(pos[i].second + k, n - 1);
      for (int j = lowi; j <= highi; ++j) {
        if (j == pos[i].first) continue;
        if (mat[j][pos[i].second] < mat[pos[i].first][pos[i].second] && dp[j][pos[i].second] >= 0)
          dp[pos[i].first][pos[i].second] = max(dp[j][pos[i].second] + mat[pos[i].first][pos[i].second], dp[pos[i].first][pos[i].second]);
      }
      for (int j = lowj; j <= highj; ++j) {
        if (j == pos[i].second) continue;
        if (mat[pos[i].first][j] < mat[pos[i].first][pos[i].second] && dp[pos[i].first][j] >= 0) 
          dp[pos[i].first][pos[i].second] = max(dp[pos[i].first][j] + mat[pos[i].first][pos[i].second], dp[pos[i].first][pos[i].second]);
      }
    }        
    /*
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cout << dp[i][j] << ' '; cout << endl;
    }*/
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
//    cerr << ans << endl;
  }
  return 0;
}