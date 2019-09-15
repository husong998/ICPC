#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define fornd(i, n) for(int i = n - 1; i >= 0; i--)
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define lsone(s) (s)&(-s)

#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 10;
int tc = 5, rn, cn, x[maxn], y[maxn], dp[maxn][1 << maxn];

int dist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

int main() {
  cin >> tc;
  while (tc--) {
    int sx, sy, n;
    cin >> rn >> cn >> sx >> sy >> n;
    forn(i, n) cin >> x[i] >> y[i];

    memset(dp, 0, sizeof dp);
    for1(i, (1 << n) - 1) {
      int ok = i;
      //cerr << bitset<5>(i) << endl;
      while (ok) {
        int lsb = lsone(ok), cur = __builtin_ctz(lsb);
        ok -= lsb;
        if (__builtin_popcount(i) == 1) dp[cur][i] = dist(sx, sy, x[cur], y[cur]);
        else {
          dp[cur][i] = INF;
          int ok1 = i - lsb;
          while (ok1) {
            int lsb2 = lsone(ok1), cur2 = __builtin_ctz(lsb2);
            ok1 -= lsb2;
            dp[cur][i] = min(dp[cur][i], dp[cur2][i - lsb] + dist(x[cur], y[cur], x[cur2], y[cur2]));
            //cerr << cur << ' ' << cur2 << endl;
          }
        }
      }
    }
    //forn(i, n) cerr << dp[i][1 << i] << ' '; cerr << endl;
    int ans = INF;
    forn(i, n) ans = min(ans, dp[i][(1 << n) - 1] + dist(sx, sy, x[i], y[i]));
    cout << ans << endl;
  }
  return 0;
}
