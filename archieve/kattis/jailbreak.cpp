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

const int N = 110, inf = 0x3f3f3f3f;
char mat[N][N];
int d[3][N][N], rdir[4] = {-1, 0, 1, 0}, cdir[4] = {0, -1, 0, 1};

struct node {
  int r, c, d;
  node(int _r, int _c, int _d): r(_r), c(_c), d(_d) {}
  bool operator < (const node b) const {
    return d > b.d;
  }
};

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif

  int tc, n, m;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    memset(mat, 0, sizeof mat);
    rep(i, 1, n + 1) scanf("%s", mat[i] + 1);

    vector<PII> ss;
    rep(i, 1, n + 1) rep(j, 1, m + 1) if (mat[i][j] == '$') ss.pb(mp(i, j));
    memset(d, inf/3, sizeof d);
    auto bfs = [&](int sr, int sc, int d[][N]) {
      priority_queue<node> q;
      q.emplace(sr, sc, 0);
      d[sr][sc] = 0;

      while (q.size()) {
        auto top = q.top(); q.pop();
        rep(i, 0, 4) {
          int nr = top.r + rdir[i], nc = top.c + cdir[i];
          if (nr >= 0 && nr < n + 2 && nc >= 0 && nc < m + 2 && mat[nr][nc] != '*') {
            int nd = top.d;
            if (mat[top.r][top.c] == '#') ++nd;
            if (nd < d[nr][nc]) {
              d[nr][nc] = nd;
              q.emplace(nr, nc, nd);
            }
          }
        }
      }
    };

    bfs(ss[0].fi, ss[0].se, d[0]);
    bfs(ss[1].fi, ss[1].se, d[1]);
    bfs(0, 0, d[2]);

    // rep(i, 0, n + 2) {
    //   rep(j, 0, m + 2) printf("%10d", d[0][i][j]); cout << endl;
    // }
    // cout << endl;
    // rep(i, 0, n + 2) {
    //   rep(j, 0, m + 2) printf("%10d", d[1][i][j]); cout << endl;
    // }
    // cout << endl;
    // rep(i, 0, n + 2) {
    //   rep(j, 0, m + 2) printf("%10d", d[2][i][j]); cout << endl;
    // }
    // cout << endl;

    int ans = inf;
    rep(i, 1, n + 1) rep(j, 1, m + 1) {
      if (mat[i][j] == '*') continue;
      int cur = 0;
      rep(k, 0, 3) cur += d[k][i][j];
      if (mat[i][j] == '#') ++cur;
      ans = min(ans, cur);
    }

    cout << ans << endl;
  }
  return 0;
}
