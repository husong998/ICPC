#include<bits/stdc++.h>
#define _for(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define _ford(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 200010;
int a[maxn], last[20], order[20], parent[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r");
  #endif
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    scanf("%d", &n);
    _for(i, 0, n) a[i] = getchar() - '0';
    int opt = 0, a, b;
    _for(x, 0, 11) {
      _for(y, x, 11) {
        memset(last, -1, sizeof last);
        memset(parent, -1, sizeof parent);

        int cur = 0;
        for (int i = 0; i < n; ++i) {
          lis[i] = 1;
          if (a[i] < x) {
            for (int j = 0; j <= a[i]; ++j) {
              if (last[j] != -1 && lis[last[j]] + 1 > lis[i]) {
                lis[i] = lis[last[j]] + 1;
                parent[i] = last[j];
              }
            }
          } else if (a[i] >= x && a[i] < y) {
            for (int j = 0; j <= x; ++j) {
              if (last[j] != -1 && lis[last[j]] + 1 > lis[i]) {
                lis[i] = lis[last[j]] + 1;
                parent[i] = last[j];
              }
            }
            for (int j = a[i]; j <= y; ++j) {
              if (last[j] != -1 && lis[last[j]] + 1 > lis[i]) {
                lis[i] = lis[last[j]] + 1;
                parent[i] = last[j];
              }
            }
          } else {
            for (int j = 0; j <= a[i]; ++j) {
              if (last[j] != -1 && lis[last[j]] + 1 > lis[i]) {
                lis[i] = lis[last[j]] + 1;
                parent[i] = last[j];
              }
            }
          }
          
          if (lis[i] > list[last[a[i]]]) last[a[i]] = i;
          if (lis[i] > lis[cur]) cur = i;
        }

        if (lis[cur] > lis[opt]) {
          opt = cur;
          a = -1; b = -1;
          while (cur != -1) {
            if (a[cur] > x && a[cur] < y && a == -1) a = cur;
            if (parent[cur] != -1 && parent[cur] < x) b = cur;
          }
        }
      }
    }
  }
  return 0;
}