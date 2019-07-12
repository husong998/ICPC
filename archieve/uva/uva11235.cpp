#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int val[maxn], id[maxn], Left[maxn], Right[maxn], a[maxn], dp[maxn][30];

int query(int l, int r) {
  int d = 0;
  while (1 << d <= r - l) ++d;
  --d;
  return max(dp[l][d], dp[r - (1 << d)][d]);
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n, q;
  while (scanf("%d", &n), n) {
    scanf("%d", &q);
    int tot = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && a[j] == a[i]) id[j] = tot, ++j;
      val[tot] = a[i];
      Left[tot] = i;
      Right[tot] = j;
      ++tot;
      i = j;
    }
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < tot; ++i) dp[i][0] = Right[i] - Left[i];
    for (int k = 1; 1 << k <= tot; ++k) {
      for (int i = 0; i + (1 << k) <= tot; ++i) 
        dp[i][k] = max(dp[i + (1 << k - 1)][k - 1], dp[i][k - 1]);
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      --l; --r;
      if (id[l] == id[r]) cout << r - l + 1 << endl;
      else {
        int ans = max(Right[id[l]] - l, r - Left[id[r]] + 1);
        ans = max(ans, query(id[l] + 1, id[r]));
        cout << ans << endl;
      }
    }
  }
  return 0;
}