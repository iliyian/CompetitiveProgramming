#include <bits/stdc++.h>
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

template<typename T>
constexpr T power(T a, u64 b) {
    T res {1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}
 
template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}
 
template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}
 
template<typename U, U P>
requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x {0} {}
    
    template<typename T>
    requires std::integral<T>
    constexpr ModIntBase(T x_) : x {norm(x_ % T {P})} {}
    
    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    
    constexpr U val() const {
        return x;
    }
    
    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }
    
    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }
    
    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }
    
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }
    
    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    
    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }
    
    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }
    
    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }
    
    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }
    
    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }
    
private:
    U x;
};
 
template<u32 P>
using ModInt = ModIntBase<u32, P>;
 
template<u64 P>
using ModInt64 = ModIntBase<u64, P>;
 
constexpr u32 P[2] = {998244353, 1000000007};
using Z = ModInt<P[0]>;

struct Comb {
  int n;
  std::vector<Z> _fac, _inv;
  Comb() : _fac{1}, _inv{0} {}
  Comb(int n) : Comb() { init(n); }
  void init(int m) {
    if (m <= n)
      return;
    _fac.resize(m + 1);
    _inv.resize(m + 1);
    for (int i = n + 1; i <= m; i++) {
      _fac[i] = _fac[i - 1] * i;
    }
    _inv[m] = _fac[m].inv();
    for (int i = m; i > n; i--) {
      _inv[i - 1] = _inv[i] * i;
    }
    n = m;
  }
  Z fac(int x) {
    if (x > n)
      init(x);
    return _fac[x];
  }
  Z inv(int x) {
    if (x > n)
      init(x);
    return _inv[x];
  }
  Z C(int x, int y) {
    if (x < 0 || y < 0 || x < y)
      return 0;
    return fac(x) * inv(y) * inv(x - y);
  }
  Z P(int x, int y) {
    if (x < 0 || y < 0 || x < y)
      return 0;
    return fac(x) * inv(x - y);
  }
} comb(1 << 21);

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n + 1);
  std::map<std::pair<int, int>, int> mp;
  std::vector<std::pair<int, int>> e;
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    e.push_back(std::minmax(x, y));
  }
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    mp[e[x - 1]] = 1 << (i - 1);
  }
  std::vector<std::vector<int>> pa(21, std::vector<int>(n + 1)), val(21, std::vector<int>(n + 1));
  std::vector<int> dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    pa[0][u] = p;
    dep[u] = dep[p] + 1;
    if (mp.count(std::minmax(u, p))) {
      val[0][u] = mp[std::minmax(u, p)];
    }
    for (int i = 1; i <= 20; i++) {
      pa[i][u] = pa[i - 1][pa[i - 1][u]];
      val[i][u] = val[i - 1][u] | val[i - 1][pa[i - 1][u]];
    }
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);
  std::vector<int> f(1 << m);
  for (int i = 1; i <= k; i++) {
    int s, t;
    std::cin >> s >> t;
    if (dep[s] < dep[t]) std::swap(s, t);
    int v = 0;
    for (int i = 20; i >= 0; i--) {
      if (dep[pa[i][s]] >= dep[t]) {
        v |= val[i][s];
        s = pa[i][s];
      }
    }
    if (s != t) {
      for (int i = 20; i >= 0; i--) {
        if (pa[i][s] != pa[i][t]) {
          v |= val[i][s] | val[i][t];
          s = pa[i][s], t = pa[i][t];
        }
      }
      v |= val[0][s] | val[0][t];
    }
    f[v] += 1;
    // for (int j = m - 1; j >= 0; j--) {
    //   std::cerr << (v >> j & 1);
    // }
    // std::cerr << '\n';
  }
  for (int i = 0; i < m; i++) {
    for (int j = (1 << m) - 1; j >= 0; j--) {
      if (j >> i & 1) {
        f[j] += f[j ^ (1 << i)];
      }
    }
  }
  // for (int i = 0; i < (1 << m); i++) {
  //   for (int j = m - 1; j >= 0; j--) {
  //     std::cerr << (i >> j & 1);
  //   }
  //   std::cerr << ' ';
  //   std::cerr << f[i ^ ((1 << m) - 1)] << '\n';
  // }
  for (int i = 1; i <= m; i++) {
    Z ans = 0;
    for (int j = (1 << m) - 1; j >= 0; j--) {
      ans += (__builtin_parityll(j) ? -1 : 1) * Z(comb.C(f[j ^ ((1 << m) - 1)], i));
    }
    if (ans != 0) {
      std::cout << i << ' ' << ans << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}