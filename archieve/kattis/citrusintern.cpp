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

const int N = 1e5 + 10;
VI adj[N];
int fa[N];
ll memo[N][2][2], c[N];

ll dp(int x, int fa, int cur) {
  if (memo[x][fa][cur] != -1) return memo[x][fa][cur];
  ll &ans = memo[x][fa][cur] = 0;
  if (adj[x].size() == 0) {
    if (fa + cur == 0) return ans = c[x];
    if (cur) return ans = c[x];
    return ans = 0;
  }
  if (fa == 1 && cur == 0) {
    for (int v : adj[x]) ans += min(dp(v, 0, 0), dp(v, 0, 1));
  } else if (fa + cur) {
    ans = c[x];
    for (int v : adj[x]) ans += dp(v, 1, 0);
  } else {
    ll delta = -1LL ^ (1LL << 63);
    // cout << delta << endl;
    for (int v : adj[x]) {
      delta = min(delta, dp(v, 0, 1) - dp(v, 0, 0));
      ans += min(dp(v, 0, 0), dp(v, 0, 1));
    }
    if (delta > 0) ans += delta;
  }
  return ans;
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif

  ios::sync_with_stdio(0);
  // cout.width(10);
  int n;
  cin >> n;
  memset(fa, -1, sizeof fa);
  rep(i, 0, n) {
    int u;
    cin >> c[i] >> u;
    rep(j, 0, u) {
      int ch;
      cin >> ch;
      adj[i].pb(ch);
      fa[ch] = i;
    }
  }

  memset(memo, -1, sizeof memo);
  ll ans = 0;
  rep(i, 0, n) if (fa[i] == -1) {
    ans += min(dp(i, 0, 0), dp(i, 0, 1));
    cout << ans << endl;
    break;
  }

  // rep(i, 0, n) {
  //   cout << memo[i][0][0] << ' ' << memo[i][0][1] << ' ' << memo[i][1][0] << endl;
  // }
  return 0;
}
