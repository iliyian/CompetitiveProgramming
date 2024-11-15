// date: 2024-11-14 23:26:54
// tag: 计数dp，等于转小于等于，高维前缀和优化

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int N = 300;

constexpr int mod = 1e9 + 7;

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

/*
templates above, i really have not much time...
fxxking the homework
*/

Z f[N + 1][N + 1][N + 1][3];
Z g[N + 1][N + 1][N + 1];

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  // memset(f, 0, sizeof(f));
  // memset(g, 0, sizeof(g));
  int cnt = 0;
  f[0][0][0][0] = f[0][0][0][1] = f[0][0][0][2] = 1;
  for (int i = 1; i <= n; i++) {
    cnt += str[i] == '?';
    if (str[i] == '?') {
      for (int j = 0; j <= cnt; j++) {
        for (int k = 0; k <= cnt; k++) {
          if (j + k > cnt) continue;
          if (j > 0) {
            f[i][j][k][0] += f[i - 1][j - 1][k][1] + f[i - 1][j - 1][k][2];
          }
          if (k > 0) {
            f[i][j][k][1] += f[i - 1][j][k - 1][0] + f[i - 1][j][k - 1][2];
          }
          f[i][j][k][2] += f[i - 1][j][k][0] + f[i - 1][j][k][1];
        }
      }
    } else {
      for (int j = 0; j <= cnt; j++) {
        for (int k = 0; k <= cnt; k++) {
          if (j + k > cnt) continue;
          if (str[i] == 'a') {
            f[i][j][k][0] += f[i - 1][j][k][1] + f[i - 1][j][k][2];
          }
          if (str[i] == 'b') {
            f[i][j][k][1] += f[i - 1][j][k][0] + f[i - 1][j][k][2];
          }
          if (str[i] == 'c') {
            f[i][j][k][2] += f[i - 1][j][k][0] + f[i - 1][j][k][1];
          }
        }
      }
    }
  }
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= cnt; j++) {
      if (i + j > cnt) continue;
      g[i][j][cnt - i - j] = f[n][i][j][0] + f[n][i][j][1] + f[n][i][j][2];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        g[i][j][k] += g[i][j][k - 1];
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        g[i][j][k] += g[i][j - 1][k];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        g[i][j][k] += g[i - 1][j][k];
      }
    }
  }
  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << g[x][y][z] / 2 << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}