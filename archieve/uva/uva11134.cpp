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
struct seg {
  int l, r, id;
  bool operator < (const seg b) const {
    return r > b.r;
  }
};
seg x[N], y[N];
int ansx[N], ansy[N];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n), n) {
    rep(i, 0, n) {
      cin >> x[i].l >> y[i].l >> x[i].r >> y[i].r;
      x[i].id = i;
      y[i].id = i;
    }
    sort(x, x + n, [](seg u, seg v) -> bool {
      return u.l < v.l;
    });
    sort(y, y + n, [](seg u, seg v) -> bool {
      return u.l < v.l;
    });
    auto solve = [&](seg x[], int ans[]) {
      int nxt = 0;
      priority_queue<seg> pq;
      rep(i, 1, n + 1) {
        while (nxt < n && x[nxt].l <= i) pq.push(x[nxt++]);
        if (pq.empty()) return false;
        if (!pq.empty() && pq.top().r < i) return false;
        ans[pq.top().id] = i;
        // cout << pq.top().id << ' ' << i << endl;
        pq.pop();
      }
      return true;
    };

    if (solve(x, ansx) && solve(y, ansy))
      rep(i, 0, n) cout << ansx[i] << ' ' << ansy[i] << endl;1
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
