#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

char str1[1010], str2[1010];
int dp[1010][1010];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  while (~scanf("%s%s", str1 + 1, str2 + 1)) {
    int n1 = strlen(str1 + 1), n2 = strlen(str2 + 1);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        if (str1[i] == str2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    cout << dp[n1][n2] << endl;
  }
  return 0;
}