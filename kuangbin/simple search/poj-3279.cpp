#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
const int maxn = 5010;
int n, m, mat[20][20], test[20][20], pos[20][20], ans[20][20], steps;
int idir[] = {-1, 0, 1, 0}, jdir[] = {0, -1, 0, 1};

void flip(int i, int j) {
  ++steps;
  pos[i][j] = 1;
  test[i][j] = 1 - test[i][j];
  for(int k = 0; k < 4; ++k) {
    if(i + idir[k] >= 0 && i + idir[k] < n && j + jdir[k] >= 0 && j + jdir[k] < m) {
      test[i + idir[k]][j + jdir[k]] = 1 - test[i + idir[k]][j + jdir[k]];
    }
  }
}

bool sol() {
  for(int i = 0; i < n - 1; ++i) {
    for(int j = 0; j < m; ++j) if(test[i][j]) flip(i + 1, j);
  }
  for(int i = 0; i < m; ++i) if(test[n - 1][i]) return 0;
  return 1;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) cin >> mat[i][j];

  int opt = 0x3f3f3f3f;
	for(int mask = 0; mask < (1 << m); ++mask) {
		memcpy(test, mat, sizeof mat);
    steps = 0;
    memset(pos, 0, sizeof pos);
		for(int i = 0; i < m; ++i)
			if(mask >> i & 1) flip(0, i);
    if(sol() && steps < opt) memcpy(ans, pos, sizeof pos), opt = steps;
	}
  if(opt == 0x3f3f3f3f) { cout << "IMPOSSIBLE"; return 0; }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) cout << ans[i][j] << ' '; cout << endl;
  }
  return 0;
}
