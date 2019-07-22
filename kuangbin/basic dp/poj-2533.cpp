#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

const int maxn = 1010;
int a[maxn], d[maxn];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    d[i] = 1;
    for (int j = 0; j < n; ++j)
      if (a[j] < a[i]) d[i] = max(d[i], d[j] + 1);
    ans = max(ans, d[i]);
  }
  cout << ans;
  return 0;
}