// date: 2025-03-24 12:39:11
// tag: 感谢很强的样例。神奇dp，属于是在根据结果凑转移式子了。不过如果维护一个信息不够，确实可以额外维护平行的信息，而不仅仅只是加一层维度，方便计算，只能说很难想

#include <bits/stdc++.h>
#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

template <typename T> constexpr T power(T a, u64 b) {
  T res{1};
  for (; b != 0; b /= 2, a *= a) {
    if (b % 2 == 1) {
      res *= a;
    }
  }
  return res;
}

template <u32 P> constexpr u32 mulMod(u32 a, u32 b) { return 1ULL * a * b % P; }

template <u64 P> constexpr u64 mulMod(u64 a, u64 b) {
  u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
  res %= P;
  return res;
}

template <typename U, U P>
  requires std::unsigned_integral<U>
struct ModIntBase {
public:
  constexpr ModIntBase() : x{0} {}

  template <typename T>
    requires std::integral<T>
  constexpr ModIntBase(T x_) : x{norm(x_ % T{P})} {}

  constexpr static U norm(U x) {
    if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
      x += P;
    }
    if (x >= P) {
      x -= P;
    }
    return x;
  }

  constexpr U val() const { return x; }

  constexpr ModIntBase operator-() const {
    ModIntBase res;
    res.x = norm(P - x);
    return res;
  }

  constexpr ModIntBase inv() const { return power(*this, P - 2); }

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

  friend constexpr std::ostream &operator<<(std::ostream &os,
                                            const ModIntBase &a) {
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

template <u32 P> using ModInt = ModIntBase<u32, P>;

template <u64 P> using ModInt64 = ModIntBase<u64, P>;

constexpr u32 P = 998244353;
using Z = ModInt<P>;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), s(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    d[i] = a[i] - a[i - 1];
  }
  d[1] = 0;
  s[0] = LLONG_MAX;
  for (int i = 2; i <= n; i++) {
    std::cin >> s[i];
  }
  std::vector<std::vector<Z>> f(n + 2, std::vector<Z>(n + 2));
  std::vector<std::vector<Z>> g(n + 2, std::vector<Z>(n + 2));
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j && j - 1 <= s[i]) {
        f[i][j] += f[i - 1][j - 1];
      }
      if (j + 1 <= s[i] && j + 1 <= i - 1) {
        f[i][j] += f[i - 1][j + 1] * (j + 1);
      }
      // std::cerr << f[i][j] << ' ';
    }
    // std::cerr << '\n';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j + 1 <= s[i] && j + 1 <= i - 1) {
        g[i][j] +=
            (g[i - 1][j + 1]
             // 对于每一个新分支都有贡献
             + d[i] * (j + 1) * f[i - 1][j + 1]
             // 没有连的点也一样向后延申，方案数代表除了那些点外的其他点构成的形态，和每次选择特定点产生的形态
             ) *
            (j + 1); // 新的分支数，导致的乘数
        // 这tmd是为什么啊？
      }
      if (j && j - 1 <= s[i]) {
        g[i][j] += g[i - 1][j - 1] + (j - 1) * d[i] * f[i - 1][j - 1]; // 整体形态是不变的
      }
      // std::cerr << g[i][j] << ' ';
    }
    // std::cerr << '\n';
  }
  std::cout << g[n][0] << '\n';
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