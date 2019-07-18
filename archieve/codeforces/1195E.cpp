#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3010;
long long mat[maxn][maxn], g[maxn * maxn], minst[3010], minmat[maxn][maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int n, m, a, b, x, y, z;
  cin >> n >> m >> a >> b;
  cin >> g[0] >> x >> y >> z;
  for(int i = 1; i < n * m; ++i) 
    g[i] = (g[i - 1] * x + y) % z;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) 
      mat[i][j] = g[i * m + j];
    
  // for(int i = 0; i < n; ++i) {
    // for(int j = 0; j < m; ++j) cout << mat[i][j] << ' ';
    // cout << endl;
  // }
  // cout << endl;

  for(int i = 0; i < n; ++i) {
    deque<long long> st;
    for(int j = 0; j < b; ++j) {
      while(!st.empty() && st.back() > mat[i][j]) st.pop_back();
      st.push_back(mat[i][j]);
    }
    
    for(int j = 0; j <= m - b; ++j) {
      minmat[i][j] = st.front();
      if(st.front() == mat[i][j]) st.pop_front();
      while(!st.empty() && st.back() > mat[i][j + b]) st.pop_back();
      st.push_back(mat[i][j + b]);
      // cout << minmat[i][j] << ' ';
    }
    // cout << endl;
  }
  // cout << n << ' ' << a << endl;
  
  long long ans = 0;
  for(int j = 0; j <= m - b; ++j) {
    deque<long long> st;
    for(int i = 0; i < a; ++i) {
      while(!st.empty() && st.back() > minmat[i][j]) st.pop_back();
      st.push_back(minmat[i][j]);
    }
    for(int i = 0; i <= n - a; ++i) {
      ans += st.front();
      if(st.front() == minmat[i][j]) st.pop_front();
      while(!st.empty() && st.back() > minmat[i + a][j]) st.pop_back();
      st.push_back(minmat[i + a][j]);
      // cout << front << ',' << rear << ' ';
    }
    // cout << endl;
  }
  cout << ans;
  return 0;
}
