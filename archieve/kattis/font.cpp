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

const int N = 110, inf = 0x3f3f3f3f;
string word[30];
int cover[30];

int lsone(int x) { return x & (-x); }

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif

  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  rep(i, 0, n) {
    cin >> word[i];
    for (char ch : word[i]) cover[i] |= 1 << (ch - 'a');
  }
  int ans = 0;
  for (int s = 1; s < 1 << n; ++s) {
    int used = 0;
    for (int ok = s; ok; ok -= lsone(ok)) used |= cover[__builtin_ctz(ok)];
    if (used == (1 << 26) - 1) ++ans;
  }
  cout << ans;
  return 0;
}
