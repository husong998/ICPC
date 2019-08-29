#include<cstdio>
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

const int N = 20010;
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

int n;
int a[N], height[N], sa[N], Rank[N];

bool check(int x) {
  int l, r;
  for (l = 1; l <= n; ++l) {
    for (r = l + 1; height[r] >= x - 1 && r <= n; ++r);
    int mp = sa[l], xp = sa[l];
    for (; l < r; ++l) {
      mp = min(mp, sa[l]);
      xp = max(xp, sa[l]);
    }
    if (xp - mp >= x) return true;
    --l;
  }
  return false;
}

bool check2(int x) {
  int l = sa[1], r = sa[1];
  for (int i = 2; i <= n; ++i) {
    if (height[i] >= x - 1) {
      l = min(l, sa[i]);
      r = max(r, sa[i]);
    } else {
      l = r = sa[i];
    }
    if (r - l >= x) return true;
  }
  return false;
}

bool judge(int c,int n)
{
    int Max=sa[1],Min=sa[1];
    for(int i=2;i<n;i++)
    {
        if(height[i]>=c)
            Max=max(Max,sa[i]),Min=min(Min,sa[i]);
        else
            Max=sa[i],Min=sa[i];
        if(Max-Min>=c+1)
            return true;
    }
    return false;
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    --n;
    for (int i = 0; i < n; ++i) a[i] = a[i + 1] - a[i] + 88;
    a[n] = 0;
    da(a, sa, Rank, height, n, 200);
    int L = 0, R = n, ans;
    while (R - L > 1) {
      int M = (L + R) >> 1;
//      cerr << M << endl;
      if (check(M)) L = M;
      else R = M;
    }
    if (L < 5) L = 0;
    cout << L << endl;

    /*
    L=0;R=n;ans=0;
    while(L<=R)
    {
        int mid=(L+R)/2;
        if(judge(mid,n+1))
            L=mid+1,ans=max(ans,mid);
        else
            R=mid-1;
    }
    if(ans<4)
        puts("0");
    else
        printf("%d\n",ans+1);
        */
  }
  return 0;
}
