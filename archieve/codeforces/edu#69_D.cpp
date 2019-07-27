#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
long long a[maxn], dp[maxn], ps[maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i];
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = max((long long)0, a[i] - k);
    for (int j = max((long long)0, i - m); j < i; ++j) dp[i] = max(dp[i], dp[j] - k + ps[i] - ps[j]);
    ans = max(ans, dp[i]);
//    cout << dp[i] << ' ';
  }
  cout << ans;
  return 0;
}