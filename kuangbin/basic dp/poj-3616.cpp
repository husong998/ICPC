#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1010;

struct inter {
  int s, t;
  long long e;
  bool operator < (const inter b) const {
    return t < b.t;
  }
};
inter a[maxn];
long long dp[maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  int n, r;
  cin >> n >> n >> r;
  for (int i = 0; i < n; ++i) {
    int s, t, e;
    cin >> s >> t >> e;
    a[i] = (inter){s, t, e};
  }
  sort(a, a + n);

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    dp[i] = a[i].e;
    for (int j = 0; j < i; ++j) {
      if (a[j].t > a[i].s - r) break;
      dp[i] = max(dp[i], dp[j] + a[i].e);
    }
    ans = max(ans, dp[i]);
  }
//  for (int i = 0; i < n; ++i) cout << a[i].s << ' ' << a[i].t << ' ' << a[i].e << endl;
//  for (int i = 0; i < n; ++i) cout << dp[i] << endl;
  cout << ans;
  return 0;
}