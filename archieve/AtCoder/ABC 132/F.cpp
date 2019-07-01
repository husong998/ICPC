#include<bits/stdc++.h>
using namespace std;

const int maxn= 40000, mod = 1e9 + 7;
const double eps = 1e-6;
long long s[maxn], b[maxn], presums[maxn], presumb[maxn];

int main() {
  #ifdef LOCAL
  //freopen("input.txt", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  int n, k, tot;
  cin >> n >> k;
  for (tot = 1; tot * tot <= n; ++tot); --tot;
  for (int i = 1; i <= tot; ++i) {
    s[i] = 1;
    b[i] = n / i - max(n / (i + 1), (int)(sqrt(n) + eps));
  }
  for (int i = 1; i <= tot; ++i) {
    presums[i] = presums[i - 1] + s[i];
    presums[i] %= mod;
    presumb[i] = presumb[i - 1] + b[i];
    presumb[i] %= mod;
  }

  for (int i = 2; i <= k; ++i) {
    for (int j = 1; j <= tot; ++j) {
      s[j] = presums[tot] + presumb[tot] - presumb[j - 1];
      s[j] %= mod;
      if (s[j] < 0) s[j] += mod;

      b[j] = (n / j - max(n / (j + 1), (int)(sqrt(n) + eps))) * presums[j];
      b[j] %= mod;
    }
    for (int j = 1; j <= tot; ++j) {
      presums[j] = presums[j - 1] + s[j];
      presums[j] %= mod;
      presumb[j] = presumb[j - 1] + b[j];
      presumb[j] %= mod;
    }
  }
  cout << (presumb[tot] + presums[tot]) % mod << endl;
  return 0;
}