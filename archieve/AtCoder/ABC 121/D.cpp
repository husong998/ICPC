#include<bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

long long getprefixxor(long long n) {
  long long ans = 0;
  ++n;
  int bitpos = 0;
  long long msb = 1 << bitpos;
  while (msb <= n - 1) {
    long long period = msb << 1;
    long long count1 = n / period * period / 2 + max(n % period - period / 2, (long long) 0);
    if (count1 & 1) ans |= ((long long)1 << bitpos);
    //debug(bitpos, count1);
    ++bitpos; msb <<= 1;
  }
  //debug(ans);
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  long long a, b;
  cin >> a >> b;
  //cout << a << ' ' << b << endl;

  // long long testa = 0, testb = 0;
  // for (int i = 0; i <= a; ++i) testa ^= i;
  // for (int i = 0; i <= b; ++i) testb ^= i;

  //cout << bitset<64>(b) << endl;
  //long long msb = 1;
  //while (msb <= b) msb <<= 1;
  //msb -= 1;
  a = getprefixxor(a - 1);
  b = getprefixxor(b);
  //cout << bitset<64>(msb) << endl;
  //cout << bitset<64>(a) << ' ' << bitset<64>(b) << endl;
  // cerr << a << ' ' << testa << endl;
  // cerr << b << ' ' << testb << endl;
  long long ans = a ^ b;
  //cout << bitset<64>(ans) << endl;
  cout << ans << endl;
  //cerr << (1L << 33);
  return 0;
}
