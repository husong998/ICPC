#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define pb push_back
typedef vector<int> VI;

// Adjacency list implementation of Dinic's blocking flow algorithm.
// This is very fast in practice, and only loses to push-relabel flow.
//
// Running time:
//     O(|V|^2 |E|)
//
// OUTPUT:
//     - maximum flow value
//     - To obtain actual flow values, look at edges with capacity > 0
//       (zero capacity edges are residual edges).

template <typename T>
class flow_graph {
 public:
  static constexpr T eps = (T) 1e-9;
 
  struct edge {
    int from;
    int to;
    T c;
    T f;
  };
 
  vector<vector<int>> g;
  vector<edge> edges;
  int n;
  int st;
  int fin;
  T flow;
 
  flow_graph(int _n, int _st, int _fin) : n(_n), st(_st), fin(_fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    flow = 0;
  }
 
  void clear_flow() {
    for (const edge &e : edges) {
      e.f = 0;
    }
    flow = 0;
  }
   
  int add(int from, int to, T forward_cap, T backward_cap) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, forward_cap, 0});
    g[to].push_back(id + 1);
    edges.push_back({to, from, backward_cap, 0});
    return id;
  }
};
 
template <typename T>
class dinic {
 public:
  flow_graph<T> &g;
 
  vector<int> ptr;
  vector<int> d;
  vector<int> q;
 
  dinic(flow_graph<T> &_g) : g(_g) {
    ptr.resize(g.n);
    d.resize(g.n);
    q.resize(g.n);
  }
 
  bool expath() {
    fill(d.begin(), d.end(), -1);
    q[0] = g.fin;
    d[g.fin] = 0;
    int beg = 0, end = 1;
    while (beg < end) {
      int i = q[beg++];
      for (int id : g.g[i]) {
        const auto &e = g.edges[id];
        const auto &back = g.edges[id ^ 1];
        if (back.c - back.f > g.eps && d[e.to] == -1) {
          d[e.to] = d[i] + 1;
          if (e.to == g.st) {
            return true;
          }
          q[end++] = e.to;
        }
      }
    }
    return false;
  }
   
  T dfs(int v, T w) {
    if (v == g.fin) {
      return w;
    }
    int &j = ptr[v];
    while (j >= 0) {
      int id = g.g[v][j];
      const auto &e = g.edges[id];
      if (e.c - e.f > g.eps && d[e.to] == d[v] - 1) {
        T t = dfs(e.to, min(e.c - e.f, w));
        if (t > g.eps) {
          g.edges[id].f += t;
          g.edges[id ^ 1].f -= t;
          return t;
        }
      }
      j--;
    }
    return 0;
  }
 
  T max_flow() {
    while (expath()) {
      for (int i = 0; i < g.n; i++) {
        ptr[i] = (int) g.g[i].size() - 1;
      }
      T big_add = 0;
      while (true) {
        T add = dfs(g.st, numeric_limits<T>::max());
        if (add <= g.eps) {
          break;
        }
        big_add += add;
      }
      if (big_add <= g.eps) {
        break;
      }
      g.flow += big_add;
    }
    return g.flow;
  }
 
  vector<bool> min_cut() {
    max_flow();
    vector<bool> ret(g.n);
    for (int i = 0; i < g.n; i++) {
      ret[i] = (d[i] != -1);
    }
    return ret;
  }
};

const int N = 50;
int mat[N][N];

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> mat[i][j];
	
	int L = 0, R = 1e6 + 1;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		int s = 2 * n, t = 2 * n + 1;
		flow_graph<int> g(2 * n + 2, 2 * n, 2 * n + 1);
		rep(i, 0, n) {
			g.add(s, i, 1, 0);
			g.add(i + n, t, 1, 0);
		}
		rep(i, 0, n) rep(j, 0, n) {
			if (mat[i][j] >= M) g.add(i, j + n, 1, 0);
		}
		dinic d(g);
		if (d.max_flow() == n) L = M;
		else R = M;
	}
	cout << L << endl;
	return 0;
}