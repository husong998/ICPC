#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int rdir[] = {0, -1, 0, 1}, cdir[] = {-1, 0, 1, 0};
int mat[10][10];
pair<int, int> fa[10][10];
int vis[10][10], n = 5, m = 5;

void printans(int r, int c) {
  if(r == 0 && c == 0) {
    cout << '(' << r << ", " << c << ")\n";
    return;
  }
  printans(fa[r][c].first, fa[r][c].second);
  cout << '(' << r << ", " << c << ")\n";
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  for(int i = 0; i < 5; ++i) for(int j = 0; j < 5; ++j) cin >> mat[i][j];
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  vis[0][0] = 1;
  while(!q.empty()) {
    int r = q.front().first, c = q.front().second;
    //cout << r << ' ' << c << endl;
    q.pop();
    if(r == n - 1 && c == m - 1) { printans(r, c); break; }
    for(int i = 0; i < 4; ++i) {
      int nr = r + rdir[i], nc = c + cdir[i];
      if(nc >= 0 && nc < 5 && nr >= 0 && nr < 5 && !vis[nr][nc]
          && mat[nr][nc] == 0) {
        q.push(make_pair(nr, nc));
        fa[nr][nc] = make_pair(r, c);
        vis[nr][nc] = 1;
      }
    }
  }
  return 0;
}
