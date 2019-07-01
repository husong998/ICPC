#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
using namespace std;

const int maxn = 10010;
int f[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n, k, m;
  while (scanf("%d%d%d", &n, &k, &m), n) {
    f[1] = 0;
    for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] + k) % i;
    int ans = (m - k + f[n]) % n;      
    if (ans < 0) ans += n;
    ++ans;
    cout << ans << endl;
  }
  return 0;
}