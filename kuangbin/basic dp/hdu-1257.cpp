#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, INF = 0x3f3f3f3f;
int d[maxn], g[maxn], a[maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    memset(g, INF, sizeof g);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int k = upper_bound(g + 1, g + n + 1, a[i]) - g;
      d[i] = k;
      g[k] = a[i];
      ans = max(ans, d[i]);
    }
    cout << ans << endl;
  }
  return 0;
}