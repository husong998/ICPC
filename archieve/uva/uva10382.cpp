#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
const double eps = 1e-6;
pair<double, double> a[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n, w, l;
  while (~scanf("%d%d%d", &n, &l, &w)) {
    int tot = 0;
    while (n--) {
      double c, r, L, R;
      scanf("%lf%lf", &c, &r);
      if (r * 2 < w - eps) continue;
      L = c - sqrt(r * r - w * w * 1.0 / 4);
      R = c + sqrt(r * r - w * w * 1.0 / 4);
      a[tot++] = make_pair(L, R);
    }
    sort(a, a + tot);
    double last = 0;
    int ok = 1, i = 0, ans = 0;
    while (i < tot && last < l - eps) {
      double nxt = last;
      int j;
      for (j = i; j < tot && a[j].first < last + eps; ++j) nxt = max(nxt, a[j].second);
      if (fabs(nxt - last) < eps) { ok = 0; break; }
      last = nxt;
      ++ans;
      i = j;
    }
    if (last < l - eps) ok = 0;
    if (ok) cout << ans << endl; else cout << -1 << endl;
  }
  return 0;
}