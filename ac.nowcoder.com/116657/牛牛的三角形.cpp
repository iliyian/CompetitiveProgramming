#include <bits/stdc++.h>
// #define int long long

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
// using Z = double;

constexpr int N = 1500;
// Z f[N + 1][16][N + 1] {};
Z s[N + 1][17][N + 1] {}, C[N + 1][N + 1];

void solve() {
  int n, m;
  std::cin >> n >> m;
  if (m >= 17) {
    std::cout << 1 << '\n';
    return;
  }
  // std::cout << 1 - s[n][m][n] / C[n][m] << '\n';
  std::cout << s[n][m][n] << ' ' << C[n][m] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int k = 1; k <= i; k++) {
      // f[i][1][k] = 1;
      s[i][1][k] = s[i][1][k - 1] + 1;
    }
  }
  for (int i = 2; i <= N; i++) {
    for (int k = 2; k <= i; k++) {
      // f[i][2][k] = k - 1;
      s[i][2][k] = s[i][2][k - 1] + k - 1;
    }
  }

  for (int i = 3; i <= N; i++) {
    for (int j = 3; j <= 16; j++) {
      for (int k = 3; k <= i; k++) {
        Z now = 0;
        if (k < i) {
          // f[i][j][k] = f[k][j][k];
          now = s[k][j][k] - s[k][j][k - 1];
        } else {
          for (int t = j - 1; t <= i - 1; t++) {
            if (i - t >= 1) { 
              int x = std::min(i - t, t - 1);
              if (x >= j - 2) {
                now += s[t - 1][j - 2][std::min(i - t, t - 1)];
              }
              // f[i][j][k] += s[t - 1][j - 2][std::min(i - t, t - 1)];
            }
          }
        }
        // s[i][j][k] = s[i][j][k - 1] + f[i][j][k];
        s[i][j][k] = s[i][j][k - 1] + now;
      }
    }
  }


  for (int i = 4; i <= 10; i++) {
    for (int j = 4; j <= 4; j++) {
      for (int k = 4; k <= i; k++) {
        std::cout << s[i][j][k] << ' ';
      }
      std::cout << '\n';
    }
  }
  // for (int i = 1; i <= 10; i++) {
  //   for (int j = 0; j <= i; j++) {
  //     std::cout << C[i][j] << ' ';
  //   }
  //   std::cout << '\n';
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}