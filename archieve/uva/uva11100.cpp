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

const int N = 1e4 + 10;
int cnt[1000010], a[N];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n), n) {
    memset(cnt, 0, sizeof cnt);
    rep(i, 0, n) cin >> a[i], cnt[a[i]]++;
    sort(a, a + n);
    int ans = *max_element(cnt, cnt + 1000000 + 10);
    cout << ans << endl;
    rep(i, 0, ans) {
      cout << a[i];
      for(int j = i + ans; j < n; j += ans) cout << ' ' << a[j];
      cout << endl;
    }
  }
  return 0;
}
