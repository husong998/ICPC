#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn = 210, INF = 0x3f3f3f3f;
int diff[maxn], sum[maxn], dp[30][40 * maxn];
vector<int> path[30][40 * maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  int n, m, kase = 0;
  while (scanf("%d%d", &n, &m), n) {
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      diff[i] = a - b;
      sum[i] = a + b;
//      cout << diff[i] << ' ' << sum[i] << endl;
    }
    int offset = n * 20;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i <= m; ++i) for (int j = 0; j <= offset * 2; ++j) path[i][j].clear();
    dp[0][offset] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = m - 1; j >= 0; --j) {
        for (int k = 0; k <= offset * 2; ++k) {
          if (dp[j][k] > -1 && dp[j + 1][k + diff[i]] < dp[j][k] + sum[i]) {
            dp[j + 1][k + diff[i]] = dp[j][k] + sum[i];
            path[j + 1][k + diff[i]] = path[j][k];
            path[j + 1][k + diff[i]].push_back(i);
          } 
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * offset; ++i) {
      if (dp[m][i] == -1) continue;
      if (abs(i - offset) < abs(ans - offset) ||
        (abs(i - offset) == abs(ans - offset) && dp[m][i] > dp[m][ans]))
        ans = i;
    }
    printf("Jury #%d\n", ++kase);
    printf("Best jury has value %d for prosecution and value %d for defence:\n", 
      (dp[m][ans] + (ans - offset)) / 2, (dp[m][ans] - (ans - offset)) / 2);
    for (int i = 0; i < path[m][ans].size(); ++i) {
      cout << ' ' << path[m][ans][i] + 1;
    }
    cout << endl << endl;
  }
  return 0;
}