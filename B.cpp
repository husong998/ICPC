#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define _ford(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define INF 0x3f3f3f3f
using namespace std;

int cntSwaps(int* perm, int n) {
  int used[20] = {0}, res = 0;
  _for(i, 0, n) {
    if (used[i]) continue;
    used[i] = 1;
    int next = perm[i];
    while (next != i) {
      used[next] = 1;
      next = perm[next];
    }
    ++res;
  }
  return n - res;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int tc;
  char str[20];
  int k;
  cin >> tc;
  while (tc--) {
    getchar();
    scanf("%s %d", str, &k);
    char maxstr[20], minstr[20];
    int len = strlen(str), perm[20];
    strcpy(maxstr, str);
    strcpy(minstr, str);
    _for (i, 0, len) perm[i] = i;
  
    do {
      if (cntSwaps(perm, len) <= k) {
        char tmp[20] = {0};
        _for(i, 0, len) tmp[i] = str[perm[i]];
        if (strcmp(tmp, maxstr) > 0) strcpy(maxstr, tmp);
        if (strcmp(tmp, minstr) < 0 && tmp[0] != '0') strcpy(minstr, tmp);
      }
    } while (next_permutation(perm, perm + len));

    cout << minstr << ' ' << maxstr << endl;
  }
  return 0;
}