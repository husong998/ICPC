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

const int N = 500010, k = 710;
ll a[N], q2[k + 10][k + 10];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      rep(i, 1, k + 1) q2[i][x % i] += y;
    } else {
      if (x <= k) cout << q2[x][y] << endl;
      else {
        ll ans = 0;
        for (int i = y; i <= 500000; i += x) ans += a[i];
        cout << ans << endl;
      }
    }
  }
  return 0;
}
