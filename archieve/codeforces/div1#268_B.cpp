#include <bits/stdc++.h>
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

const int N = 1e5 + 10;
int fa[N], a[N], sel[N], sta[N];
map<int, int> id;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  int n, A, B;
  ios::sync_with_stdio(0);
  cin >> n >> A >> B;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    id[a[i]] = i;
    fa[i] = i;
    sta[i] = 3;
  }                        

  for (int i = 0; i < n; ++i) {
    if (id.count(A - a[i])) fa[find(id[A - a[i]])] = find(i), sel[i] |= 1;
    if (id.count(B - a[i])) fa[find(id[B - a[i]])] = find(i), sel[i] |= 2;
  }

  for (int i = 0; i < n; ++i) {
    sta[find(i)] &= sel[i];
//    cout << fa[i] << ' ';
    if (sta[find(i)] == 0) { cout << "NO"; return 0; }
  }
  cout << endl;

  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << __builtin_ctz(sta[find(i)]) << ' ';
  }
  return 0;
}
