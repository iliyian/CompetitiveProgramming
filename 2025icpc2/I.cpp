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

auto lagrange_interpolation(const std::vector<int> &x,
                                        const std::vector<Z> &y,
                                      int k) {
  const int n = x.size();
  std::vector<Z> M(n + 1), px(n, 1), f(n);
  M[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      M[j + 1] = M[j] + M[j + 1];
      M[j] = -M[j] * x[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        px[i] = px[i] * (x[i] - x[j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    Z t = y[i] * px[i].inv(), k = M[n];
    for (int j = n - 1; j >= 0; --j) {
      f[j] = f[j] + k * t;
      k = M[j] + k * x[i];
    }
  }
  Z ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ans = ans * k + f[i];
  }
  return std::make_pair(f, ans);
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
  }
  std::vector<int> x(n);
  std::vector<Z> y(n);
  for (int i = 1; i <= n - 1; i++) {
    x[i] = i;
    std::cout << "? " << 1 << ' ' << n << ' ' << i << std::endl;
    int ans;
    std::cin >> ans;
    y[i] = ans;
  }
  std::cout << "!" << std::endl;
  int k;
  std::cin >> k;
  auto [f, ans] = lagrange_interpolation(x, y, k);
  std::cout << ans << std::endl;
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