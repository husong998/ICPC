#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 1010, INF = 0x3f3f3f3f;
int d[maxn][maxn], vis[maxn][maxn];
char mat[maxn][maxn];
int rdir[] = {0, -1, 0, 1}, cdir[] = {-1, 0, 1, 0};

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int tc;
  cin >> tc;
  while(tc--) {
    int n, m, ok = 0;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) scanf("%s", mat[i]);
    queue<pair<int, int> > q;
    memset(d, INF, sizeof d);
    int jr, jc;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
      if(mat[i][j] == 'F') {
        q.push(make_pair(i, j));
        d[i][j] = 0;
        //cout << i << ' ' << j << ' ' << d[i][j] << endl;
      } else if(mat[i][j] == 'J') { jr = i; jc = j; }
    while(!q.empty()) {
      int r = q.front().first, c = q.front().second;
      q.pop();
      for(int i = 0; i < 4; ++i) {
        int nr = r + rdir[i], nc = c + cdir[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m 
            && mat[nr][nc] != '#' && d[nr][nc] == INF) {
          q.push(make_pair(nr, nc));
          d[nr][nc] = d[r][c] + 1;
        }
      }
    }
    //for(int i = 0; i < n; ++i) {
    //for(int j = 0; j < m; ++j) cout << d[i][j] << ' ';
    //cout << endl;
    //}
    q.push(make_pair(jr, jc));
    memset(vis, -1, sizeof vis);
    vis[jr][jc] = 0;
    while(!q.empty()) {
      int r = q.front().first, c = q.front().second;
      q.pop();
      if(r == 0 || r == n - 1 || c == 0 || c == m - 1) {
        cout << vis[r][c] + 1 << endl;
        ok = 1;
        break;
      }
      //cout << r << ' ' << c << endl;
      for(int i = 0; i < 4; ++i) {
        int nr = r + rdir[i], nc = c + cdir[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.'
            && vis[r][c] + 1 < d[nr][nc] && vis[nr][nc] == -1) {
          q.push(make_pair(nr, nc));
          vis[nr][nc] = vis[r][c] + 1;
        }
      }
    }
    if(!ok) cout << "IMPOSSIBLE\n";
  }
  return 0;
}
