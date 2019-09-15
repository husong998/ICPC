#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < b; ++i)

const int N = 110;
char mat[N][N];
int cdir[] = {-2, -2, -1, 1, 2, 2, 1, -1}, rdir[] = {1, -1, -2, -2, -1, 1, 2, 2};

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	#endif
	ios::sync_with_stdio(0);
	int n;
	string str;
	cin >> n;
	cin >> str;
	string pat("ICPCASIASG");
	reverse(all(pat));
	//~ queue<PIII> q;
	rep(i, 0, n) rep(j, 0, n) {
		mat[i][j] = str[i * n + j];
	}
	function<bool(int, int, int)> dfs = [&](int r, int c, int p) {
		if (p == pat.size() - 1) return true;
		for (int i = 0; i < 8; ++i) {
			int nr = rdir[i] + r, nc = cdir[i] + c;
			if (nr >= 0 && nr < n && nc >= 0 && nc < n && mat[nr][nc] == pat[p + 1] && dfs(nr, nc, p + 1))
				return true;
		}
		return false;
	};
	int ok = 0;
	rep(i, 0, n) rep(j, 0, n) {
		if (mat[i][j] == 'G' && dfs(i, j, 0)) ok = 1;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}