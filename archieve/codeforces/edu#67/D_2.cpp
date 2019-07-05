#include<bits/stdc++.h>
using namespace std;

const int maxn = 300010, INF = 0x3f3f3f3f;
int t[4 * maxn], a[maxn], b[maxn];

void build_tree(int v, int tl, int tr) {
  if (tl == tr) t[v] = a[tl];
  else {
    int m = (tl + tr) / 2;
    build_tree(v * 2, tl, m);
    build_tree(v * 2 + 1, m + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return INF;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) /  2;
  return min(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
  if (tl == tr) t[v] = new_val;
  else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(v * 2, tl, tm, pos, new_val);
    else update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    set<pair<int, int>> pos;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      pos.insert(make_pair(a[i], i));
    }
    build_tree(1, 0, n - 1);
    int ok = 1;
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
      int cur = b[i];
      auto p = pos.lower_bound(make_pair(cur, 0));
      if (p == pos.end() || p->first != cur || query(1, 0, n - 1, 0, p->second) < p->first) {
        ok = 0;
        break;
      }
      update(1, 0, n - 1, p->second, n);
      pos.erase(p);
    }
    if (ok) cout << "YES" << endl; else cout << "NO" << endl;
  }
  return 0;
}