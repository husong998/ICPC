#include<bits/stdc++.h>
using namespace std;

string str[60];

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; ++i) cin >> str[i];
    sort(str, str + n, [](string a, string b) -> bool { return a + b > b + a; });
    for (int i = 0; i < n; ++i) cout << str[i];
    cout << endl;
  }
  return 0;
}