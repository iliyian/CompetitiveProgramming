// date: 2025-03-03 22:02:19
// tag: 挺有意思的算贡献的dp，以及子序列似乎一般都需要前缀和，毕竟是子序列嘛

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
  std::string str, a, b;
  std::cin >> str >> a >> b;
  int n = str.size(), alen = a.size(), blen = b.size();
  str = '#' + str;
  a = '#' + a;
  b = '#' + b;
  std::vector<std::array<std::array<Z, 21>, 21>> f(n + 1, {0});
  for (int i = 1; i <= n; i++) {
    // if (str[i] == a[1]) {
    //   f[i][1][0] = i;
    // }
    // if (str[i] == b[1]) {
    //   f[i][0][1] = i;
    // }
    // if (str[i] == a[1] && str[i] == b[1]) {
    //   f[i][1][1] = i;
    // }
    for (int j = 0; j <= alen; j++) {
      for (int k = 0; k <= blen; k++) {
        if (!j && !k) continue;
        f[i][j][k] += f[i - 1][j][k];
        if (str[i] == a[j]) {
          f[i][j][k] += (j == 1 && k == 0 ? i : f[i - 1][j - 1][k]);
        }
        if (str[i] == b[k]) {
          f[i][j][k] += (j == 0 && k == 1 ? i : f[i - 1][j][k - 1]);
        }
        if (str[i] == a[j] && str[i] == b[k]) {
          f[i][j][k] += (j == 1 && k == 1 ? i : f[i - 1][j - 1][k - 1]);
        }
      }
    }
    // std::cerr << f[i][alen][blen] << '\n';
    // for (int j = 0; j <= alen; j++) {
    //   for (int k = 0; k <= blen; k++) {
    //     std::cerr << f[i][j][k] << ' ';
    //   }
    //   std::cerr << '\n';
    // }
    // std::cerr << '\n';
  }
  Z ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (f[i][alen][blen] - f[i - 1][alen][blen]) * (n - i + 1);
  }
  std::cout << ans << '\n';
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