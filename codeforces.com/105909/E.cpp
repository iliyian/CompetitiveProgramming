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
 
constexpr u32 P = 1000000007;
using Z = ModInt<P>;
// using Z = int;

void solve() {
  int n, h, k, _x;
  std::cin >> n >> h >> k >> _x;
  Z inv100 = Z(100).inv();
  Z x = _x * inv100;
  std::vector<Z> q(n + 1), p(n + 1), px(501);
  px[0] = 1;
  for (int i = 1; i <= 500; i++) {
    px[i] = px[i - 1] * x;
  }
  for (int i = 1; i <= n; i++) {
    int v;
    std::cin >> v;
    q[i] = v * inv100;
  }
  for (int i = 1; i <= n; i++) {
    int v;
    std::cin >> v;
    p[i] = v * inv100;
  }
  std::vector<std::vector<Z>> f(n + 1, std::vector<Z>(501));
  f[0][0] = 1;
  Z ans = 1;
  for (int i = 1; i <= n; i++) {
    double cur = (p[i] * 100).val() / 100.0;
    int mx = 0;
    // p[i]*px[mx]<=1
    while (mx + 1 <= h - 1) {
      if (cur * _x / 100.0 > 1) break;
      mx++;
      cur *= _x / 100.0;
    }
    // std::cerr << mx << '\n';
    // mx = 500;
    for (int j = 0; j <= mx + 1; j++) {
      if (j != mx + 1)
        f[i][j] += f[i - 1][j] * (1 - p[i] * px[j]) * (1 - q[i]);
      if (j != 0)
        f[i][j] += f[i - 1][j - 1] * (1 - p[i] * px[j - 1]) * q[i];
    }
    if (k != 0 && i % k == 0 || i == n) {
      Z cur = 0;
      for (int j = 0; j <= std::min(mx + 1, h - 1); j++) {
        cur += f[i][j];
      }
      for (int j = 1; j <= 500; j++) {
        f[i][j] = 0;
      }
      f[i][0] = cur;
      // std::cerr << cur << '\n';
      // f[i][0] = 1;
    }
  }
  std::cout << f[n][0].inv() << '\n';
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