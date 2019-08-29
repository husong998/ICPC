#include <bits/stdc++.h>

using namespace std;

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cnt, w;
  cin >> cnt >> w;
  vector<long long> ans(1 + w);
  while (cnt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int front = 0, rear = 0;
    deque<int> dq;
    for (int i = 0; i < w; ++i) {
      if (i < n) {
        while (dq.size() && dq.back() < a[rear]) dq.pop_back();
        dq.push_back(a[rear]);
        ++rear;
      }
      if (i > w - n) {
        if (dq.size() && dq.front() == a[front]) dq.pop_front();
        ++front;
      }
      int cur = dq.front();
      if (i >= n || i < w - n) cur = max(0, cur);
      ans[i] += cur;
//      cout << "i: " << i << ", ";
      if (i == n - 1 && i < w - n) i = w - n;
      ans[i + 1] -= cur;
//      cout << "i+1: " << i + 1 << ", " << "cur: " << cur << endl;
//      for (int j = 0; j < w; ++j) cout << ans[j] << ' '; cout << endl;
    }
  }
  for (int i = 0; i < w; ++i) {
    cout << ans[i] << ' ';
    ans[i + 1] += ans[i];
  }
  return 0;
}