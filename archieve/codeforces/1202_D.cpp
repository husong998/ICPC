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

const int N = 5010, INF = 0x3f3f3f3f;

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif

  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    ll n, cnt3 = 2;
    cin >> n;
    while (cnt3 * (cnt3 - 1) / 2 <= n) ++cnt3;
    --cnt3;
    n -= cnt3 * (cnt3 - 1) / 2;
    cout << 1;
    cout << 33;
    rep(i, 0, n) cout << 7;
    rep(i, 0, cnt3 - 2) cout << 3;
    cout << 7 << endl;
  }
  return 0;
}
