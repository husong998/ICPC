#include<bits/stdc++.h>
using namespace std;

const int maxn = 20;
int cover[1 << maxn], S[maxn], dp[1 << maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n, kase = 0;
  while (scanf("%d", &n), n) {
    memset(S, 0, sizeof S);
    memset(cover, 0, sizeof cover);
    for (int i = 0; i < n; ++i) {
      int k;
      scanf("%d", &k);
      S[i] |= 1 << i;
      while (k--) {
        int u;
        scanf("%d", &u);
        S[i] |= 1 << u;
      }
    }

    for (int mask = 0; mask < 1 << n; ++mask) {
      for (int j = 0; j < n; ++j) {
        if (mask >> j & 1) {
          cover[mask] |= S[j];
        }
      }
    }

    memset(dp, 0, sizeof dp);

    for (int mask = 1; mask < 1 << n; ++mask) {
      for (int submask = mask; submask; submask = (submask - 1) & mask) {
        if (cover[submask] == (1 << n) - 1) dp[mask] = max(dp[mask], 1 + dp[mask ^ submask]);
      }
    }

    printf("Case %d: %d\n", ++kase, dp[(1 << n) - 1]);
  }
  return 0;
}