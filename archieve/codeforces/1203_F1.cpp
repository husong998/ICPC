#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
 
const int N = 100 + 10, INF = 0x3f3f3f3f;
const double eps = 1e-6;
PII a[N], bad[N];
int used[N], dp[N][int(6e4 + 10)];
 
int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif
 
  ios::sync_with_stdio(0);
  int n, r;
  cin >> n >> r;
  int cntbad = 0;
  rep(i, 0, n) {
    cin >> a[i].fi >> a[i].se;
    if (a[i].se < 0) bad[cntbad++] = a[i];
  }
 
  sort(bad, bad + cntbad, [](PII u, PII v) -> bool {
    return u.fi + u.se > v.fi + v.se;
  });
 
  int ok = 1, taken = 0;
  while (1) {
    int choose = -1;
    rep(i, 0, n) 
      if (!used[i] && a[i].se >= 0 && a[i].fi <= r) {
        choose = i;
        break;
      }
    if (choose == -1) break;
    r += a[choose].se;
    used[choose] = 1;
    ++taken;
  }
 
  memset(dp, -1, sizeof dp);
  dp[0][r] = taken;
  rep(i, 0, cntbad) {
    rep(j, 0, 6e4 + 10) {
      if (dp[i][j] != -1) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if (j >= bad[i].fi && j + bad[i].se >= 0)
          dp[i + 1][j + bad[i].se] = max(dp[i + 1][j + bad[i].se], dp[i][j] + 1);
      }
    }
  }
 
  int ans = 0;
  rep(i, 0, 6e4 + 10) {
    ans = max(ans, dp[cntbad][i]);
  }
  cout << ans;
  return 0;
}