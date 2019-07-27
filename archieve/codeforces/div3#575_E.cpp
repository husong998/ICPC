#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int r[maxn], c[maxn];
  	
int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int b, w, morew = 0, tot = 0;
    cin >> b >> w;
    if (w > b) swap(w, b), morew = 1;
    if (b > w * 3 + 1) { cout << "NO\n"; continue; }
    
    for (int i = 2; i < 2 + w * 2 - 1; ++i) r[tot] = 2, c[tot] = i, ++tot;
    b -= w - 1;

    for (int i = 2; i < 2 + w * 2 - 1 && b; ++i) {
      if ((i + 1) & 1) r[tot] = 1, c[tot] = i, ++tot, --b;
    }
    for (int i = 2; i < 2 + w * 2 - 1 && b; ++i) {
      if ((i + 3) & 1) r[tot] = 3, c[tot] = i, ++tot, --b;
    }
    if (b) r[tot] = 2, c[tot] = 1, --b, ++tot;
    if (b) r[tot] = 2, c[tot] = 2 + 2 * w - 1, ++tot;

    cout << "YES\n";
    for (int i = 0; i < tot; ++i) {
      if (morew) cout << r[i] + 1;
      else cout << r[i];
      cout << ' ' << c[i] << endl;
    }
  }
  return 0;
}