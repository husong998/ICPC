#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
using namespace std;

const int maxn = 100010;
int a[maxn], presum[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n, s;
  while (~scanf("%d%d", &n, &s)) {
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) presum[i] = presum[i - 1] + a[i];
    int j = 1, ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
      if (presum[i] - presum[j - 1] < s) continue;
      for (j; presum[i] - presum[j] >= s; ++j);
      ans = min(ans, i - j + 1);
    }
    if (ans == 0x3f3f3f3f) cout << 0 << endl;
    else cout << ans << endl;
  }
  return 0;
}