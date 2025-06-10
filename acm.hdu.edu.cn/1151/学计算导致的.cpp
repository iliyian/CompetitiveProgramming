// date: 2025-03-21 16:35:36
// tag: 将高维dp转换为自动机的一类题目，预先压缩状态和转移，然后就很方便
// 小技巧的 int j = 1 + (i == 1)，然后就可以从(1,1)设置初始状态为1了，我也不知道为什么，但这样就是能不wa

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
// requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x {0} {}
    
    template<typename T>
    // requires std::integral<T>
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

Z f[101][101][8001];
int nxt[128][8001], k;

int r(int sum, int cof, int cur) {
  sum %= k, cof %= k, cur %= k;
  return (sum * k + cof) * k + cur;
}

void solve() {
  int n, m;
  std::cin >> n >> m >> k;
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int a = 0; a < k * k * k; a++) {
        f[i][j][a] = 0; 
      }
    }
  }
  for (int sum = 0; sum < k; sum++) {
    for (int cof = 0; cof < k; cof++) {
      for (int cur = 0; cur < k; cur++) {
        for (char i = '0'; i <= '9'; i++) {
          nxt[i][r(sum, cof, cur)] = r(sum, cof, cur * 10 + i - '0');
        }
        nxt['+'][r(sum, cof, cur)] = r(sum + cof * cur, 1, 0);
        nxt['-'][r(sum, cof, cur)] = r(sum + cof * cur, k - 1, 0);
        nxt['*'][r(sum, cof, cur)] = r(sum, cof * cur, 0);
      }
    }
  }
  Z ans = 0;
  f[1][1][r(0, 1, a[1][1] - '0')] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1 + (i == 1); j <= m; j++) {
      for (int S = 0; S < k * k * k; S++) {
        if (isdigit(a[i][j]) || isdigit(a[i - 1][j])) {
          f[i][j][nxt[a[i][j]][S]] += f[i - 1][j][S];
        }
        if (isdigit(a[i][j]) || isdigit(a[i][j - 1])) {
          f[i][j][nxt[a[i][j]][S]] += f[i][j - 1][S];
        }
      }
    }
  }
  for (int sum = 0; sum < k; sum++) {
    for (int cof = 0; cof < k; cof++) {
      for (int cur = 0; cur < k; cur++) {
        if ((sum + cof * cur) % k == 0) {
          // std::cerr << sum << ' ' << cof << ' ' << cur << ' ' << f[n][m][r(sum, cof, cur)] << '\n';
          ans += f[n][m][r(sum, cof, cur)];
        }
      }
    }
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