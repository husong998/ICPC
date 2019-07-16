#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;

int taken[10010];
set<string> primes;

string to_string(int n) {
  char res[10] = {0};
  int pos = 0;
  while(n) {
    res[pos++] = n % 10 + '0';
    n /= 10;
  }
  reverse(res, res + pos);
  return res;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  for(int i = 2; i < 1e4; ++i) {
    if(!taken[i]) {
      if(i > 1e3) {
        primes.insert(to_string(i));
        // cout << to_string(i) << endl;
      }
      for(int j = i * i; j < 1e4; j += i) taken[j] = 1;
    }
  }
  // for(set<string>::iterator it = primes.begin(); it != primes.end(); ++it)
    // cout << *it << ' ';
  // cout << endl;
  while(tc--) {
    set<string> vis;
    string a, b;
    cin >> a >> b;
    queue<pair<string, int> > q;
    q.push(make_pair(a, 0));
    vis.insert(a);
    while(!q.empty()) {
      string cur = q.front().first;
      int d = q.front().second;
      // cout << cur << ',' << d << endl;
      q.pop();
      if(cur == b) {
        cout << d << endl;
        break;
      }
      string nxt = cur;
      for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 10; ++j) {
          if(j + '0' != cur[i]) {
            nxt[i] = j + '0';
            if(primes.count(nxt) && !vis.count(nxt)) {
              q.push(make_pair(nxt, d + 1));
              vis.insert(nxt);
            }
            nxt[i] = cur[i];
          }
        }
      }
    }
  }
  return 0;
}
