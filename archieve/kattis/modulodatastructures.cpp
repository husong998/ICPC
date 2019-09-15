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

const int N = 200010, K = 450;
ll bucket[K + 10][K + 10], sum[N];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b, c;
      cin >> a >> b >> c;
      if (b <= K) bucket[b][a] += c;
      else {
        for (int i = a; i <= n; i += b) {
          sum[i] += c;
        }
      }
    } else {
      int d;
      cin >> d;
      ll ans = sum[d];
      rep(i, 1, K + 1) {
        ans += bucket[i][d % i];
      }
      cout << ans << endl;
    }
  }
  return 0;
}