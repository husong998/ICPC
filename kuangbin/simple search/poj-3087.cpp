#include<iostream>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 210;
char s[maxn], s1[maxn], s2[maxn], s12[maxn], init[maxn];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  for(int kase = 1; kase <= tc; ++kase) {
    int ans = 0, n;
    memset(s1, 0, sizeof s1);
    memset(s2, 0, sizeof s2);
    memset(s12, 0, sizeof s12);
    memset(s, 0, sizeof s);
    cin >> n >> s1 >> s2 >> s12;
    int ok = 0;
    set<string> vis;
    for(;;) {
      for(int i = 0; i < 2 * n; ++i)
        if(i & 1) s[i] = s1[i / 2];
        else s[i] = s2[i / 2];
      // cout << s << endl;
      ++ans;
      if(strcmp(s, s12) == 0) {
        ok = 1;
        break;
      }
      if(vis.count(s)) break;
      vis.insert(s);
      strncpy(s1, s, n);
      strncpy(s2, s + n, n);
    }
    cout << kase << ' ';
    if(ok) cout << ans << endl;
    else cout << -1 << endl;
  }
  return 0;
}
