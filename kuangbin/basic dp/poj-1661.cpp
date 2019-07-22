#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn = 1010;

struct board {
  int x1, x2, h;
  bool operator < (const board &b) const { return h > b.h; }
};
board a[maxn];
int Left[maxn], Right[maxn], dp[maxn][2];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, x, y, mh;
    cin >> n >> x >> y >> mh;
    a[0] = (board){x, x, y};
    for (int i = 1; i <= n; ++i) {
      int x1, x2, h;
      cin >> x1 >> x2 >> h;
      a[i] = (board){x1, x2, h};
    }
    a[++n] = (board){-20000, 20000, 0};
    ++n;
    sort(a, a + n);
    for (int i = 0; i < n - 1; ++i) Left[i] = n - 1, Right[i] = n - 1;

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[j].x1 <= a[i].x1 && a[j].x2 >= a[i].x1 && a[Left[i]].h < a[j].h) Left[i] = j;
        if (a[j].x1 <= a[i].x2 && a[j].x2 >= a[i].x2 && a[Right[i]].h < a[j].h) Right[i] = j;
      }
    }

    memset(dp, 0x3f3f3f3f, sizeof dp);
    dp[0][1] = dp[0][0] = 0;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n - 1; ++i) {
      if (dp[i][0] == -1) continue;
      if (a[i].h - a[Left[i]].h <= mh) {
        dp[Left[i]][0] = min(dp[Left[i]][0], dp[i][0] + abs(a[i].x1 - a[Left[i]].x1) + a[i].h - a[Left[i]].h);
        dp[Left[i]][1] = min(dp[Left[i]][1], dp[i][0] + abs(a[i].x1 - a[Left[i]].x2) + a[i].h - a[Left[i]].h);
      }
      if (a[i].h - a[Right[i]].h <= mh) {
        dp[Right[i]][0] = min(dp[Right[i]][0], dp[i][1] + abs(a[i].x2 - a[Right[i]].x1) + a[i].h - a[Right[i]].h);
        dp[Right[i]][1] = min(dp[Right[i]][1], dp[i][1] + abs(a[i].x2 - a[Right[i]].x2) + a[i].h - a[Right[i]].h);
      }
      if (Left[i] == n - 1 && a[i].h <= mh) ans = min(ans, dp[i][0] + a[i].h);
      if (Right[i] == n - 1 && a[i].h <= mh) ans = min(ans, dp[i][1] + a[i].h);
    }
    /*
    for (int i = 0; i < n; ++i) cout << a[i].x1 << ' ' << a[i].x2 << ' ' << a[i].h << endl; cout << endl;
    for (int i = 0; i < n; ++i) cout << Left[i] << ' ' << Right[i] << endl; cout << endl;
    for (int i = 0; i < n; ++i) cout << dp[i][0] << ' ' << dp[i][1] << endl;*/
    cout << ans << endl;
  }
  return 0;
}