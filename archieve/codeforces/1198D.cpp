#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;

const int N = 50 + 10;
int dp[N][N][N][N], ps[N][N];
char mat[N][N];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
                          
  int n;
  cin >> n;                  
  rep(i, 1, n + 1) scanf("%s", mat[i] + 1);
  rep(i, 1, n + 1) {
    rep(j, 1, n + 1) {
      ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + (mat[i][j] == '#');
    }
  }

  auto get = [&](int i, int j, int ii, int jj) {
    return ps[ii][jj] - ps[i][jj] - ps[ii][j] + ps[i][j];
  };

  per(i, 1, n + 2) {
    rep(ii, i, n + 2) {
      per(j, 1, n + 2) {
        rep(jj, j, n + 2) {
          if (i == ii || j == jj) dp[i][ii][j][jj] = 0;
          else dp[i][ii][j][jj] = max(ii - i, jj - j);

          rep(k, i, ii)
            if (get(k - 1, j - 1, k, jj - 1) == 0)
              dp[i][ii][j][jj] = min(dp[i][ii][j][jj], dp[i][k][j][jj] + dp[k + 1][ii][j][jj]);

          rep(k, j, jj)
            if (get(i - 1, k - 1, ii - 1, k) == 0)
              dp[i][ii][j][jj] = min(dp[i][ii][j][jj], dp[i][ii][j][k] + dp[i][ii][k + 1][jj]);
//          cout << i << ',' << ii << ',' << j << ',' << jj << ',' << ':' << dp[i][ii][j][jj] << endl;
        }
      }
    }
  }

  cout << dp[1][n + 1][1][n + 1];
  return 0;
}
