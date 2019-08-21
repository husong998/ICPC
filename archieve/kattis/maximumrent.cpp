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

const int N = 40, inf = 0x3f3f3f3f;

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif

  int a, b, m, sig;
  cin >> a >> b >> m >> sig;
  vector<PII> pts;
  pts.emplace_back(1, m - 1);
  pts.emplace_back(m - 1, 1);
  pts.emplace_back(1, 1);
  pts.emplace_back(sig - m, 2 * m - sig);
  pts.emplace_back(1, sig - 2);
  pts.emplace_back(sig / 2 - 1, 2);
  pts.emplace_back(sig / 2, 1);
  pts.emplace_back(sig / 2, 2);
  
  ll ans = 0;
  for (auto pt : pts) {
    int x = pt.fi, y = pt.se;
    if (x >= 1 && y >= 1 && x + y <= m && 2 * x + y >= sig) ans = max(ans, (ll)a * x + b * y);
  }
  cout << ans;
  return 0;
}
