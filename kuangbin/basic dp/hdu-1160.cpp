#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, INF = 0x3f3f3f3f;
int d[maxn], fa[maxn], s[maxn], w[maxn], a[maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  int tot = 0;
  while (~scanf("%d%d", &w[tot], &s[tot])) ++tot;
  iota(a, a + tot, 0);

  sort(a, a + tot, [](int v1, int v2) -> bool {
    return s[v1] > s[v2];
  });
//  for (int i = 0; i < tot; ++i) cout << w[a[i]] << ' ' << s[a[i]] << endl;
  memset(fa, -1, sizeof fa);
  int ans = 0;
  for (int i = 0; i < tot; ++i) {
    for (int j = 0; j < i; ++j) {
      if (s[a[j]] > s[a[i]] && w[a[j]] < w[a[i]] && d[i] < d[j]) {
        d[i] = d[j];
        fa[i] = j;
      }
    }
    ++d[i];
    if (d[i] > d[ans]) ans = i;
  }
//  for (int i = 0; i < tot; ++i) cout << d[i] << ' '; cout << endl;
//  cout << ans << endl;
  cout << d[ans] << endl;
  function<void(int)> printans = [&](int u){
    if (u == -1) return;
    printans(fa[u]);
    cout << a[u] + 1 << endl;
    return;
  };
  printans(ans);
  return 0;
}