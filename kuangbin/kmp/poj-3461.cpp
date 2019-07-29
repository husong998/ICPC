#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int m, f[N];
char p[N], t[N];

void getfail() {
  f[0] = f[1] = 0;
  for (int i = 1; i < m; ++i) {
    int j = f[i];
    while (j && p[j] != p[i]) j = f[j];
    if (p[j] == p[i]) f[i + 1] = j + 1;
    else f[i + 1] = 0;
  }
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> p >> t;
    m = strlen(p);
    getfail();
    
//    for (int i = 0; i <= m; ++i) cout << f[i] << ' '; cout << endl;

    int j = 0, ans = 0, n = strlen(t);
    for (int i = 0; i < n; ++i) {
      while (j && p[j] != t[i]) j = f[j];
      if (p[j] == t[i]) ++j;
      if (j == m) ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
