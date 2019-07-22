#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef pair<int, int> pii;

const int maxn = 1010;
char mat[maxn][maxn];
int dp[maxn][maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  int n;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i) scanf("%s", mat[i]);
    memset(dp, 0, sizeof dp);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = n - 1; j >= 0; --j) {
        int k;
        for (k = 0; i - k >= 0 && j + k < n && mat[i - k][j] == mat[i][j + k]; ++k);
        if (i > 0 && j < n - 1 && k > dp[i - 1][j + 1]) dp[i][j] = dp[i - 1][j + 1] + 1;
        else dp[i][j] = k;
//        cout << k << ' ';
        ans = max(ans, dp[i][j]);
      }
//      cout << endl;
    }
    cout << ans << endl;
  }
  return 0;
}