#include<bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

const int maxn = 1e6 + 10;      
int f[maxn], deg[maxn], dist[maxn];
vector<int> adj[maxn];

void getfail(string p) {
  int n = p.size();
  for (int i = 1; i < n; ++i) {
    int j = f[i];
    while (j && p[j] != p[i]) j = f[j];
    if (p[j] == p[i]) f[i + 1] = j + 1;
  }
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  ios::sync_with_stdio(false);
  string s, t, s1;
  cin >> s >> t;
  getfail(t);
  s1 = s;
  int m = t.size(), n = s.size();
  while (s.size() < s1.size() + t.size()) s += s1;

  int j = 0;
  for (int i = 0; i < n + m; ++i) {
    while (j && t[j] != s[i]) j = f[j];
    if (t[j] == s[i]) ++j;
    if (j == m) adj[(i - m + 1) % n].push_back((i + 1) % n), ++deg[(i + 1) % n];
  }

  queue<int> q;
  int ans = 0;
  for (int i = 0; i < n; ++i) if (deg[i] == 0) q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : adj[u])
      if (--deg[v] == 0) q.push(v), dist[v] = max(dist[v], dist[u] + 1), ans = max(ans, dist[v]);;
  }
  
  int ok = 1;
  for (int i = 0; i < n; ++i) if (deg[i]) { ok = 0; break; }

  if (!ok) cout << -1;
  else cout << ans;
  return 0;
}