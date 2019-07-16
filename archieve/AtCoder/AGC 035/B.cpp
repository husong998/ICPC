#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

pair<int, int> edge[maxn];
int taken[maxn], deg[maxn], ansu[maxn], ansv[maxn], fa[maxn], tot;
vector<int> adj[maxn];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int u, int parent) {
  for(auto v : adj[u]) {
    if(v != parent) dfs(v, u);
  }
  if(parent == -1) return;
  if(deg[u] & 1) ansu[tot] = u, ansv[tot] = parent, ++tot;
  else ansu[tot] = parent, ansv[tot] = u, deg[parent] ^= 1, ++tot;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  if(m & 1) { cout << -1; return 0; }
  for(int i = 0; i < m; ++i) {
    cin >> edge[i].first >> edge[i].second;
  }
  for(int i = 1; i <= n; ++i) fa[i] = i;
  int root;
  for(int i = 0; i < m; ++i)
    if(find(edge[i].first) != find(edge[i].second)) {
      fa[find(edge[i].second)] = find(edge[i].first);
      root = edge[i].first;
      adj[edge[i].first].push_back(edge[i].second);
      adj[edge[i].second].push_back(edge[i].first);
    }
    else {
      ansu[tot] = edge[i].first;
      ansv[tot] = edge[i].second;
      ++tot;
      deg[edge[i].first] ^= 1;
    }
  dfs(root, -1);
  for(int i = 0; i < m; ++i)
    cout << ansu[i] << ' ' << ansv[i] << endl;
  return 0;
}
