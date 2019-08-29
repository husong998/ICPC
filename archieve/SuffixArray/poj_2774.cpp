#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
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

const int N = 2e5 + 10;
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

char str1[N], str2[N];
int s[N], height[N], Rank[N], sa[N];

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  scanf("%s", str1);
  scanf("%s", str2);
  int n = strlen(str1), m = strlen(str2);
  for (int i = 0; i < n; ++i) s[i] = str1[i];
  for (int i = 0; i < m; ++i) s[i + n + 1] = str2[i];
  da(s, sa, Rank, height, n + m + 1, 'z' + 1);
  int ans = 0;
  for (int i = 2; i <= m + n + 2; ++i) {
    if ((sa[i - 1] < n && sa[i] > n) || (sa[i - 1] > n && sa[i] < n)) {
      ans = max(ans, height[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
