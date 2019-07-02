#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 300010, INF = 0x3f3f3f3f;
int t[4 * maxn], b[maxn];
deque<int> s[maxn];
 
void build_tree(int v, int tl, int tr) {
  if (tl == tr) t[v] = s[tl].empty() ? INF : s[tl][0];
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
    for (int i = 1; i <= n; ++i) s[i].clear();
    for (int i = 0; i < n; ++i) {
      int cur;
      cin >> cur;
      s[cur].push_back(i);
    }
    for (int i = 0; i < n; ++i) cin >> b[i];
    build_tree(1, 1, n);
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      if (s[b[i]].empty() || query(1, 1, n, 1, b[i] - 1) < s[b[i]].front()) {
        ok = 0;
        break;
      }
      s[b[i]].pop_front();
      if (!s[b[i]].empty()) update(1, 1, n, b[i], s[b[i]].front());
      else update(1, 1, n, b[i], INF);
    }
    if (ok) cout << "YES" << endl; else cout << "NO" << endl;
  }
  return 0;
}