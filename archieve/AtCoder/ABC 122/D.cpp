#include <bits/stdc++.h>
using namespace std;

string to_string(string s)
{
  return '"' + s + '"';
}

string to_string(const char *s)
{
  return to_string((string)s);
}

string to_string(bool b)
{
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v)
{
  bool first = true;
  string res = "{";
  for (const auto &x : v)
  {
    if (!first)
    {
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
void debug_out(Head H, Tail... T)
{
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <std::uint32_t mod>
class modint
{
private:
  std::uint32_t n;

public:
  modint() : n(0){};
  modint(std::uint64_t n_) : n(n_ % mod){};
  bool operator==(const modint &m) const { return n == m.n; }
  bool operator!=(const modint &m) const { return n != m.n; }
  std::uint32_t get() const { return n; }
  modint &operator+=(const modint &m)
  {
    n += m.n;
    n = (n < mod ? n : n - mod);
    return *this;
  }
  modint &operator-=(const modint &m)
  {
    n += mod - m.n;
    n = (n < mod ? n : n - mod);
    return *this;
  }
  modint &operator*=(const modint &m)
  {
    n = std::uint64_t(n) * m.n % mod;
    return *this;
  }
  modint operator+(const modint &m) const { return modint(*this) += m; }
  modint operator-(const modint &m) const { return modint(*this) -= m; }
  modint operator*(const modint &m) const { return modint(*this) *= m; }
  modint binpow(std::uint64_t b) const
  {
    modint ans = 1, m = modint(*this);
    while (b)
    {
      if (b & 1)
        ans *= m;
      m *= m;
      b >>= 1;
    }
    return ans;
  }
  modint inv() { return (*this).binpow(mod - 2); }
};

const int mod = 1e9 + 7, N = 110;
using modulo = modint<mod>;

modulo dp[N][5][5][5];

int main()
{
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;

  char ch[10] = "ACGT";
  unordered_map<char, int> id({{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}});
  unordered_set<string> fbd({"AGC", "ACG", "GAC"});

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      for (int k = 0; k < 4; ++k) {
        string tmp;
        tmp.push_back(ch[i]);
        tmp.push_back(ch[j]);
        tmp.push_back(ch[k]);
        if (fbd.count(tmp) == false) dp[2][i][j][k] = modulo(1);
      }
  for (int i = 3; i < n; ++i)
    for (int k = 0; k < 4; ++k)
      for (int l = 0; l < 4; ++l)
        for (int m = 0; m < 4; ++m) {
          string tmp;
          tmp.push_back(ch[k]);
          tmp.push_back(ch[l]);
          tmp.push_back(ch[m]);
          if (fbd.count(tmp)) continue;
          for (int j = 0; j < 4; ++j) {
            string tmp2;
            tmp2.push_back(ch[j]);
            tmp2.push_back(ch[k]);
            tmp2.push_back(ch[m]);

            tmp[0] = ch[j];
            if (tmp != "AGC" && tmp2 != "AGC") {
              dp[i][k][l][m] += dp[i - 1][j][k][l];
            }
          }
          // cerr << ch[k] << ch[l] << ch[m] << ' ' << dp[i][k][l][m].get();
          // cerr << endl;
        }
  modulo ans;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k)
        ans += dp[n - 1][i][j][k];
    }
  }
  cout << ans.get();
  return 0;
}
