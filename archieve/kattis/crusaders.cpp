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

const int N = 1e6 + 10, bs = 1 << 13;
ll block[210], income[110];
int ans[210];

int main() {
  #ifdef LOCAL
  // freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif

  ios::sync_with_stdio(0);
  int c, a;
  cin >> c >> a;
  rep(i, 0, a) cin >> income[i];

  int tot;
  for (tot = 1; tot * bs < c; ++tot) {
    cout << "Q " << tot * bs + 1 << endl;
    cout.flush();
    cin >> block[tot];
  }
  block[0] = 0;
  block[tot++] = 1e13;

  rep(i, 0, a) {
    ll cur = income[i];
    int pos = upper_bound(block, block + tot, cur) - block - 1;
    int lb = pos * bs + 1, ub = min(lb + bs, c + 1);
    while (ub - lb > 1) {
      int m = (ub + lb) >> 1;
      ll v;
      cout << "Q " << m << endl;
      cout.flush();
      cin >> v;
      if (v > cur) ub = m;
      else lb = m;
    }
    ans[i] = lb;
  }

  cout << 'A';
  rep(i, 0, a) cout << ' ' << ans[i];
  cout << endl;
  return 0;
}
