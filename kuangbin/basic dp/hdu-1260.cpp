#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2010;
int a[maxn], b[maxn], dp[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 2; i <= n; ++i) cin >> b[i];
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1] + a[i];
      if(i > 1) dp[i] = min(dp[i], dp[i - 2] + b[i]);
    }

    int HH = 8, am = 1, MM = 0, SS = 0;
    SS += dp[n];
    MM = SS / 60;
    SS %= 60;
    HH += MM / 60;
    MM %= 60;
    if(HH >= 12) am = 0;
    if(HH > 12) HH -= 12;
    cout << setw(2) << setfill('0') << HH << ':';
    cout << setw(2) << setfill('0') << MM << ':';
    cout << setw(2) << setfill('0') << SS;
    if(am) cout << " am\n";
    else cout << " pm\n";
  }
  return 0;
}
