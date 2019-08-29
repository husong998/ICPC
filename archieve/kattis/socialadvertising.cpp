#include <bits/stdc++.h>

using namespace std;

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> cover(n);
    for (int i = 0; i < n; ++i) {
      int len;
      cin >> len;
      cover[i] |= 1 << i;
      for (int j = 0; j < len; ++j) {
        int x;
        cin >> x;
        --x;
        cover[i] |= 1 << x;
      }
    }
    int ans = 0x3f3f3f3f;
    function<void(int, int, int)> solve = [&](int choose, int c, int cur) {
      if (c == (1 << n) - 1) ans = min(ans, __builtin_popcount(choose));
      if (cur == n) return;
      solve(choose, c, cur + 1);
      solve(choose | (1 << cur), c | cover[cur], cur + 1);
    };
    solve(0, 0, 0);
    cout << ans << endl;
  }
  return 0;
}