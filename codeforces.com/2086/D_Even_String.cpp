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
 
constexpr int mod = 998244353;
constexpr int N = 5e5;
int inv[N + 1], fac[N + 1], invfac[N + 1];

int C(int n, int m) {
  if (n < m) return 0;
  if (m < 0) return 0;
  return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void solve() {
  int c[27] {}, s[27] {};
  int sum = 0;
  for (int i = 1; i <= 26; i++) {
    std::cin >> c[i];
    s[i] = s[i - 1] + c[i];
    sum += c[i];
  }
  int s1 = sum / 2, s2 = sum - s1;
  std::vector<std::vector<std::array<Z, 2>>> f(27, std::vector<std::array<Z, 2>>(s1 + 1, {0, 0}));
  f[0][0][0] = f[0][0][1] = 1;
  Z ans = 0;
  for (int i = 1; i <= 26; i++) {
    if (!c[i]) {
      std::copy(f[i - 1].begin(), f[i - 1].end(), f[i].begin());
      continue;
    }
    for (int j = s1; j >= 0; j--) {
      f[i][j][0] += f[i - 1][j][0] * C(s2 - (s[i - 1] - j), c[i]);
      f[i][j][0] += f[i - 1][j][1] * C(s2 - (s[i - 1] - j), c[i]);
      if (j >= c[i]) {
        f[i][j][1] += f[i - 1][j - c[i]][0] * C(s1 - (j - c[i]), c[i]);
        f[i][j][1] += f[i - 1][j - c[i]][1] * C(s1 - (j - c[i]), c[i]);
      }
    }
  }
  std::cout << (f[26][s1][0] + f[26][s1][1]) * Z(2).inv() << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  inv[1] = fac[1] = invfac[1] = fac[0] = invfac[0] = 1;
  for (int i = 2; i <= N; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i - 1] * i % mod;
    invfac[i] = invfac[i - 1] * inv[i] % mod;
  }
  // std::cerr << C(132, 66) << '\n';

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}