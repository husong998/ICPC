#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1010], a[1010];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n;
  while(scanf("%d", &n), n) {
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      dp[i] = a[i];
      for(int j = 0; j < n; ++j) 
        if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + a[i]);
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
