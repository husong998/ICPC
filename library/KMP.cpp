#include<bits/stdc++.h>
using namespace std;
/* KMP algorithm
*  p is pattern string, t is text string
*  m is pattern string length, n is text string length
*  call match() to get all the matching positions
*/
const int N = 1e6 + 10;
int m, f[N], n;
char p[N], t[N];

void getfail() {
  f[0] = f[1] = 0;
  for (int i = 1; i < m; ++i) {
    int j = f[i];
    while (j && p[j] != p[i]) j = f[j];
    if (p[j] == p[i]) f[i + 1] = j + 1;
    else f[i + 1] = 0;
  }
}

vector<int> match() {
  vector<int> ans;
  int j = 0;
  for (int i = 0; i < n; ++i) {
    while (j && p[j] != t[i]) j = f[j];
    if (p[j] == t[i]) ++j;
    if (j == m) {
      ans.push_back(i - m + 1);
    }
  }
  return ans;
}

int main() {
  strcpy(t, "GATAGACA$");
  n = strlen(t);
  strcpy(p, "GA");
  m = 2;
  getfail();
  auto ans = match();
  // should output 0 4
  for (auto e : ans) cout << e << ' '; cout << endl;
}
