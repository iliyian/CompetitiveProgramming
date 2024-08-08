// date: 2024-08-07 12:21:40
// tag: 期望dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

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

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> a = {{-1, 0, 0}};

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int v;
      std::cin >> v;
      a.push_back({v, i, j});
    }
  }

  int sx, sy;
  std::cin >> sx >> sy;

  std::sort(a.begin() + 1, a.end());
  int len = n * m;
  std::vector<Z> x2(len + 1), y2(len + 1), xs(len + 1), ys(len + 1);
  std::vector<Z> f(len + 1), F(len + 1);
  int r = 0;
  for (int i = 1; i <= len; i++) {
    auto [v, x, y] = a[i];
    x2[i] = x2[i - 1] + x * x, y2[i] = y2[i - 1] + y * y;
    xs[i] = xs[i - 1] + x, ys[i] = ys[i - 1] + y;
    if (v != a[r][0]) {
      r = i;
    }
    if (r == 1)
      continue;
    f[i] = (r - 1) * (x * x + y * y) + x2[r - 1] + y2[r - 1] + F[r - 1] -
           2 * xs[r - 1] * x - 2 * ys[r - 1] * y;
    f[i] /= (r - 1);
    F[i] = F[i - 1] + f[i];
    if (x == sx && y == sy) {
      std::cout << f[i] << '\n';
      return 0;
    }
  }
  std::cout << 0 << '\n';

  return 0;
}