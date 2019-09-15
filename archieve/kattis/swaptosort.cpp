#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define pb push_back
typedef vector<int> VI;

const int N = 1e6 + 10;
int vis[N];
VI g[N];

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	int n, e;
	cin >> n >> e;
	rep(i, 0, e) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int cnt = 0;
	function<void(int, int)> dfs = [&](int u, int c) {
		vis[u] = c;
		for (int v : g[u]) {
			if (!vis[v]) dfs(v, c);
		}
	};
	int ok = 1;
	rep(i, 0, n) {
		if (!vis[i]) {
			dfs(i, ++cnt);
		}
	}
	//~ rep(i, 0, n) cout << vis[i] << ' ';
	//~ cout << endl;
	rep(i, 0, n / 2) {
		if (vis[i] != vis[n - 1 - i]) {
			ok = 0;
			break;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}