#include<bits/stdc++.h>
using namespace std;
/* solution for kattis magicallights
   do dfs to re-index vertices because all the vertices in a subtree are contiguous in dfs order
   each subtree then correspond to a subarray, which can be queried and updated online using fenwick tree
 */

const int maxn = 300010;
int c[maxn], l[maxn], r[maxn], tot, n;
vector<int> adj[maxn];
// using range xor for parity check, the number of odd colors correponds to the number of on bits in the range xor
bitset<110> ft[maxn];

int dfs(int u, int fa) {
  l[u] = r[u] = ++tot;
  for (auto v : adj[u]) {
    if (v != fa)
      r[u] = max(r[u], dfs(v, u));
  }
  return r[u];
}

int lowbit(int x) { return x & (-x); }

void update(int x, bitset<110> d) {
  while (x <= n) {
    ft[x] ^= d;
    x += lowbit(x);
  }
}

bitset<110> sum(int x) {
  bitset<110> res;
  while (x) {
    res ^= ft[x];
    x -= lowbit(x);
  }
  return res;
}

bitset<110> query(int L, int R) { return sum(R) ^ sum(L); }

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int qn;
  cin >> n >> qn;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 2; i <= n; ++i) {
    int fa;
    cin >> fa;
    adj[fa].push_back(i);
    adj[i].push_back(fa);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; ++i) {
    bitset<110> tmp;
    tmp.set(c[i]);
    update(l[i], tmp);
  }

  while (qn--) {
    int k, x;
    cin >> k >> x;
    if (k) {
      bitset<110> tmp;
      tmp.set(c[x]);
      c[x] = k;
      tmp.flip(k);
      update(l[x], tmp);
    } else {
      cout << query(l[x] - 1, r[x]).count() << endl;
    }
  }
  return 0;
}