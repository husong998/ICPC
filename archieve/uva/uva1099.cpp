#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n, a[maxn], area[1 << maxn], f[110][1 << maxn];

int dp(int r, int s) {
  if (__builtin_popcount(s) == 1) return 1;
  if (f[r][s] != -1) return f[r][s];
  
  int c = area[s] / r;
  for (int s1 = (s - 1) & s; s1; s1 = (s1 - 1) & s) {
    int s2 = s ^ s1;
    if (area[s1] % r == 0 && dp(min(r, area[s1] / r), s1) && dp(min(r, area[s2] / r), s2)) return f[r][s] = 1;
    if (area[s1] % c == 0 && dp(min(c, area[s1] / c), s1) && dp(min(c, area[s2] / c), s2)) return f[r][s] = 1;
  }
  return f[r][s] = 0;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int kase = 0;
  while (scanf("%d", &n), n) {
    memset(area, 0, sizeof area);
    memset(f, -1, sizeof f);
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < 1 << n; ++i) {
      for (int j = 0; j < n; ++j) if (i >> j & 1) area[i] += a[j];
    }
    if (r > c) swap(r, c);
    printf("Case %d: ", ++kase);
    if (area[(1 << n) - 1] != r * c) cout << "No\n";
    else if (dp(r, (1 << n) - 1)) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}