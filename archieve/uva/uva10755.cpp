#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
using namespace std;

const int maxn = 30;
long long vol[maxn][maxn][maxn], sum2d[maxn][maxn], sum[maxn], mss[maxn];

/* idea: dimenssion redection
enumerating the starting and ending index of the first dimension, calculate the 2D sum matrix over the first dimenssion
then enumerating the starting and ending index of the second dimension, converting it into a 1D max range sum problem.
 */
 
int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    _for(i, 1, a) _for(j, 1, b) _for(k, 1, c) scanf("%lld", &vol[i][j][k]);

    long long ans = -(1LL << 60);
    _for(z1, 1, a) {
      memset(sum2d, 0, sizeof sum2d);
      _for(z2, z1, a) {
        _for(i, 1, b) _for(j, 1, c) sum2d[i][j] += vol[z2][i][j];
        
        _for(y1, 1, b) {
          memset(sum, 0, sizeof sum);
          _for(y2, y1, b) {
            _for(i, 1, c) sum[i] += sum2d[y2][i];
            memset(mss, 0, sizeof mss);
            _for(i, 1, c) {
              mss[i] = max(mss[i - 1] + sum[i], sum[i]);
              ans = max(ans, mss[i]);
            }
          }
        }
      }
    }

    cout << ans << endl;
    if (tc) cout << endl;
  }
}