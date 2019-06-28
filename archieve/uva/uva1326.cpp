#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
using namespace std;

const int maxn = 30;
char str[maxn];
int a[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n;
  while (~scanf("%d", &n)) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      int len = strlen(str);
      for (int j = 0; j < len; ++j) {
        a[i] ^= 1 << (str[j] - 'A');
      }
    }

    unordered_map<int, int> used;
    for (int mask = 0; mask < 1 << (n / 2); ++mask) {
      int cur = 0;
      for (int i = 0; i < (n / 2); ++i) {
        if (mask >> i & 1) cur ^= a[i];
      }
      if (!used.count(cur) || __builtin_popcount(mask) > __builtin_popcount(used[cur])) used[cur] = mask;
    }

    int ans = 0;

    for (int mask = 0; mask < 1 << (n - n / 2); ++mask) {
      int cur = 0;
      for (int i = n / 2; i < n; ++i) {
        if (mask >> (i - n / 2) & 1) cur ^= a[i];
      }
      if (used.count(cur)) {
        int tmp = (mask << (n / 2)) | used[cur];
        if (__builtin_popcount(tmp) > __builtin_popcount(ans)) ans = tmp;
      }
    }

    cout << __builtin_popcount(ans) << endl;
    for (int i = 0; i < n; ++i) {
      if (ans >> i & 1) cout << i + 1 << ' ';
    }
    cout << endl;
  }
  return 0;
}