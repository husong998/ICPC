#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6 + 10;
int m, f[N];
int p[N], t[N];

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
    int n;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < m; ++i) cin >> p[i];

    getfail();

    int j = 0, ok = 0;
    for (int i = 0; i < n; ++i) {
      while (j && p[j] != t[i]) j = f[j];
      if (p[j] == t[i]) ++j;
      if (j == m) {
        ok = 1;
        cout << i - m + 2 << endl;
        break;
      }
    }
    if (!ok) cout << -1 << endl;
  }
  return 0;
}
