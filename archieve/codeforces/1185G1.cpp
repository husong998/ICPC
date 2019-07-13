#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxn = 20, mod = 1e9 + 7;
int t[maxn], g[maxn];
int n, T;
ll memo[maxn][1 << maxn];

int lowbit(int s) { return s & (-s); }

int sum(int s) {
  int res = 0;
  for(int i = 0; i < n; ++i)
	if(s >> i & 1) res += t[i];
  return res;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  cin >> n >> T;
  for(int i = 0; i < n; ++i) {
	cin >> t[i] >> g[i];
  }
  ll ans = 0;
  for(int mask = 1; mask < (1 << n); ++mask) {
	int add = 0;
	if(sum(mask) == T) add = 1;
	if(__builtin_popcount(mask) == 1) {
	  memo[__builtin_ctz(mask)][mask] = 1;
	  if(add) ans += memo[__builtin_ctz(mask)][mask], ans %= mod;
	} else
	  for(int k = mask; k; k -= lowbit(k)) {
		int subs = mask ^ lowbit(k), cur = __builtin_ctz(k);
		for(int i = subs; i; i -= lowbit(i)) {
		  int nxt = __builtin_ctz(i);
		  if(g[nxt] != g[cur]) {
			memo[cur][mask] += memo[nxt][subs];
			memo[cur][mask] %= mod;
		  }
		}
		if(add) ans += memo[cur][mask], ans %= mod;
	  }
  }
    //for(int mask = 0; mask < (1 << n); ++mask) {
  	//cout << bitset<5>(mask) << ": ";
  	//for(int i = 0; i < n; ++i) cout << memo[i][mask] << ' ';
  	//cout << endl;
    //}
  cout << ans;
  return 0;
}
