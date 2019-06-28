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