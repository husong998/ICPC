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

const int N = 10010, INF = 0x3f3f3f3f;

struct task {
  int l, r, w;
  bool operator < (const task b) const {
    return r > b.r;
  }
};

task a[N];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif

  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    rep(i, 0, n) cin >> a[i].l >> a[i].r >> a[i].w;

    sort(a, a + n, [](task u, task v) -> bool {
      return u.l < v.l;
    });

    int L = 0, R = INF;

    auto check = [&](int x) -> bool {
      priority_queue<task> pq;
      int nxt = 0;
      rep(i, 1, 20001) {
        int rem = x;
        while (nxt < n && a[nxt].l < i) pq.push(a[nxt++]);
        if (!pq.empty() && i > pq.top().r) return 0;
        while (!pq.empty() && rem) {
          auto u = pq.top();
          // cout << u.l << ' ' << u.r << ' ' << u.w << endl;
          pq.pop();
          if (u.w > rem) {
            u.w -= rem;
            pq.push(u);
            rem = 0;
          } else {
            rem -= u.w;
          }
        }
      }
      return pq.empty();
    };
    while (R - L > 1) {
      int mid = (R + L) / 2;
      // cout << mid << ' ' << check(mid) << endl;
      if (check(mid)) R = mid;
      else L = mid;
    }
    cout << R << endl;
  }
  return 0;
}
