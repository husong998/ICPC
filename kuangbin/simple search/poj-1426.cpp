#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
long long dfs(long long cur, int d) {
  if(d > 19) return 0;
  if(cur % n == 0) return cur;
  long long val = dfs(cur * 10, d + 1);
  if(val) return val;
  else return dfs(cur * 10 + 1, d + 1);
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  while(scanf("%d", &n), n) {
    cout << dfs(1, 1) << endl;
  }
  return 0;
}