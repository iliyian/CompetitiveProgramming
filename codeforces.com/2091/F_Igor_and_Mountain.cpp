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
 
constexpr u32 P = 998244353;
using Z = ModInt<P>;

void solve() {
  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector<std::string> a(n + 1);
  std::vector<std::vector<Z>> f(n + 1, std::vector<Z>(m + 1));
  std::vector<std::vector<Z>> g(n + 1, std::vector<Z>(m + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  for (int i = 1; i <= m; i++) {
    f[n][i] = (a[n][i] == 'X' ? 1 : 0);
    g[n][i] = g[n][i - 1] + f[n][i];
  }
  int len = d - 1;
  for (int j = 1; j <= m; j++) {
    int l = std::max(1ll, j - d), r = std::min(m, j + d);
    // std::cerr << j << ' ' << l << ' ' << r << ' ' << len << '\n';
    if (a[n][j] == 'X') {
      f[n][j] += g[n][r] - g[n][l - 1] - f[n][j];
      // std::cerr << f[n][j] << " \n"[j == m];
    }
  }
  for (int i = 1; i <= m; i++) {
    g[n][i] = g[n][i - 1] + f[n][i];
    // std::cerr << f[n][i] << " \n"[i == m];
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      int l = std::max(1ll, j - len), r = std::min(m, j + len);
      if (a[i][j] == 'X') {
        f[i][j] += g[i + 1][r] - g[i + 1][l - 1];
      }
    }
    for (int j = 1; j <= m; j++) {
      g[i][j] = g[i][j - 1] + f[i][j];
    }
    for (int j = 1; j <= m; j++) {
      int l = std::max(1ll, j - d), r = std::min(m, j + d);
      // if (i == 1 && j == 2) {
        // std::cerr << j << ' ' << l << ' ' << r << ' ' << d << '\n';
        // std::cerr << g[i][r] << ' ' << g[i][l - 1] << '\n';
      // }
      if (a[i][j] == 'X') {
        f[i][j] += g[i][r] - g[i][l - 1] - f[i][j];
      }
    }
    for (int j = 1; j <= m; j++) {
      g[i][j] = g[i][j - 1] + f[i][j];
      // std::cerr << f[i][j] << " \n"[j == m];
    }
  }
  Z ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // std::cerr << f[i][j] << " \n"[j == m];
    }
  }
  for (int i = 1; i <= m; i++) {
    ans += f[1][i];
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}