#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>

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

/* 
* suffix array
* length of the array to be sorted is n, add 0 at the end
* Rank[0...n - 1] are valid values
* sa[1..n] are valid values as s[0] = n
* heigh[2...n] are valid values
*/

const int N = 1e5 + 110;
int t1[N], t2[N], c[N]; // intermediate variables, no need to assign values
// put string into str array, length of str should be n, max(str) should be smaller than m

bool cmp(int *r, int a, int b, int l) {
  return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int str[], int sa[], int Rank[], int height[], int n, int m) {
  ++n;
  int i, j, p, *x = t1, *y = t2;
  // first round of radix sort, if max(str) is big, change to qsort
  for (i = 0; i < m; ++i) c[i] = 0;
  for (i = 0; i < n; ++i) ++c[x[i] = str[i]];
  for (i = 1; i < m; ++i) c[i] += c[i - 1];
  for (i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
  for (j = 1; j <= n; j <<= 1) {
    p = 0;
    for (i = n - j; i < n; ++i) y[p++] = i;
    for (i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < m; ++i) c[i] = 0;
    for (i = 0; i < n; ++i) c[x[y[i]]]++;
    for (i = 1; i < m; ++i) c[i] += c[i - 1];
    for (i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
    swap(x, y);
    p = 1; x[sa[0]] = 0;
    for (i = 1; i < n; ++i)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    if (p >= n) break;
    m = p;
  }
  int k = 0;
  --n;
  for (i = 0; i <= n; ++i) Rank[sa[i]] = i;
  for (i = 0; i < n; ++i) {
    if (k) --k;
    j = sa[Rank[i] - 1];
    while (str[i + k] == str[j + k]) ++k;
    height[Rank[i]] = k;
  }
}

int s[N], height[N], Rank[N], sa[N], id[N], ans[N];
char str[110][1010];
int len[110], vis[110];
int n, x = 0, kase = 0, pos;

bool check(int M) {
  memset(vis, 0, sizeof vis);
  int cnt = 0;
  int p = 0;
  for (int i = n + 1; i < x; ++i) {
    if (height[i] < M) {
      if (cnt > n / 2) ans[p++] = sa[i - 1];
      memset(vis, 0, sizeof vis);
      cnt = 0;
    } else {
      if (vis[id[sa[i - 1]]] == 0) {
        vis[id[sa[i - 1]]] = 1;
        ++cnt;
      }
      if (vis[id[sa[i]]] == 0) {
        vis[id[sa[i]]] = 1;
        ++cnt;
      }
    }
  }
  if (cnt > n / 2) ans[p++] = sa[x - 1];
  if (p) {
    pos = p;
    return true;
  }
  return false;
}

// void printans(int M) {
  // for (int l = n; l < x; ++l) {
    // set<int> cover;
    // cover.insert(id[sa[l]]);
    // int r = l + 1;
    // for (; height[r] >= M && r < x; ++r)
      // cover.insert(id[sa[r]]);
    // if (cover.size() > n / 2) {
      // for (int j = sa[l]; j < sa[l] + M; ++j)
        // putchar(s[j] - 4);
      // cout << endl;
    // }
    // l = r - 1;
  // }
// }

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  
  while (scanf("%d", &n), n) {
    pos = 0;
    if (kase) cout << endl;
    kase = 1;
    x = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%s", str[i]);
      len[i] = strlen(str[i]);
      for (int j = 0; j < len[i]; ++j) {
        s[x] = str[i][j] + 4;
        id[x++] = i;
      }
      s[x++] = i;
      len[i] = x;
    }
    if (n == 1) {
      cout << str[0] << endl;
      continue;
    }
    da(s, sa, Rank, height, x - 1, 'z' + 4 + 1);
    int L = 0, R = x;
    while (R - L > 1) {
      int M = (L + R) >> 1;
      if (check(M)) L = M;
      else R = M;
    }
    if (L == 0) cout << "?" << endl;
    else {
      for (int i = 0; i < pos; ++i) {
        for (int j = ans[i]; j < ans[i] + L; ++j)
          putchar(s[j] - 4);
        cout << endl;
      }
    }
  }
  return 0;
}
