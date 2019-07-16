#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

tuple<int, int, int> cube[600];
int dp[600];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int kase = 0, n;
  while(scanf("%d", &n), n) {
    for(int i = 0; i < n; ++i) {
      int a[3];
      for(int j = 0; j < 3; ++j) scanf("%d", &a[j]);
      int perm[3];
      iota(perm, perm + 3, 0);
      int cnt = 0;
      do {
        cube[i * 6 + cnt] = make_tuple(a[perm[0]], a[perm[1]], a[perm[2]]);
        ++cnt;
      } while(next_permutation(perm, perm + 3));
    }
    sort(cube, cube + 6 * n);
    int ans = 0;
    for(int i = 0; i < 6 * n; ++i) {
      int x, y, z;
      tie(x, y, z) = cube[i];
      dp[i] = z;
      for(int j = 0; j < i; ++j) {
        int px, py, pz;
        tie(px, py, pz) = cube[j];
        if(px < x && py < y) dp[i] = max(dp[i], dp[j] + z);
      }
      ans = max(ans, dp[i]);
    }
    printf("Case %d: maximum height = %d\n", ++kase, ans);
  }
  return 0;
}
