// date: 2025-03-14 17:24:12
// tag: 矩阵树定理板子，拉格朗日插值板子

#include <bits/stdc++.h>
#include <functional>
#define int long long
using namespace std;
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

template <u32 P> constexpr u32 mulP(u32 a, u32 b) { return 1ULL * a * b % P; }

template <u64 P> constexpr u64 mulP(u64 a, u64 b) {
  u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
  res %= P;
  return res;
}

template <typename U, U P>
  // requires std::unsigned_integral<U>
struct PIntBase {
public:
  constexpr PIntBase() : x{0} {}

  template <typename T>
    // requires std::integral<T>
  constexpr PIntBase(T x_) : x{norm(x_ % T{P})} {}

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

  constexpr PIntBase operator-() const {
    PIntBase res;
    res.x = norm(P - x);
    return res;
  }

  constexpr PIntBase inv() const { return power(*this, P - 2); }

  constexpr PIntBase &operator*=(const PIntBase &rhs) & {
    x = mulP<P>(x, rhs.val());
    return *this;
  }

  constexpr PIntBase &operator+=(const PIntBase &rhs) & {
    x = norm(x + rhs.x);
    return *this;
  }

  constexpr PIntBase &operator-=(const PIntBase &rhs) & {
    x = norm(x - rhs.x);
    return *this;
  }

  constexpr PIntBase &operator/=(const PIntBase &rhs) & {
    return *this *= rhs.inv();
  }

  friend constexpr PIntBase operator*(PIntBase lhs, const PIntBase &rhs) {
    lhs *= rhs;
    return lhs;
  }

  friend constexpr PIntBase operator+(PIntBase lhs, const PIntBase &rhs) {
    lhs += rhs;
    return lhs;
  }

  friend constexpr PIntBase operator-(PIntBase lhs, const PIntBase &rhs) {
    lhs -= rhs;
    return lhs;
  }

  friend constexpr PIntBase operator/(PIntBase lhs, const PIntBase &rhs) {
    lhs /= rhs;
    return lhs;
  }

  friend constexpr std::ostream &operator<<(std::ostream &os,
                                            const PIntBase &a) {
    return os << a.val();
  }

  friend constexpr bool operator==(PIntBase lhs, PIntBase rhs) {
    return lhs.val() == rhs.val();
  }

  friend constexpr bool operator!=(PIntBase lhs, PIntBase rhs) {
    return lhs.val() != rhs.val();
  }

  friend constexpr bool operator<(PIntBase lhs, PIntBase rhs) {
    return lhs.val() < rhs.val();
  }

private:
  U x;
};

template <u32 P> using PInt = PIntBase<u32, P>;

template <u64 P> using PInt64 = PIntBase<u64, P>;

constexpr u32 P = 1000000007;
using Z = PInt<P>;

int detP(int n, std::vector<std::vector<int>> &mat) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      mat[i][j] %= P;
  int ret = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)
      while (mat[j][i] != 0) {
        int t = mat[i][i] / mat[j][i];
        for (int k = i; k < n; k++) {
          mat[i][k] = (mat[i][k] - mat[j][k] * t) % P;
          int s = mat[i][k];
          mat[i][k] = mat[j][k];
          mat[j][k] = s;
        }
        ret = -ret;
      }
    if (mat[i][i] == 0)
      return 0;
    ret = ret * mat[i][i] % P;
  }
  if (ret < 0)
    ret += P;
  return ret;
}

using LL = long long;
constexpr int MOD = P;

int inv(int x) { return power(Z(x), MOD - 2).val(); }

std::vector<int> lagrange_interpolation(const std::vector<int> &x,
                                        const std::vector<int> &y) {
  const int n = x.size();
  std::vector<int> M(n + 1), px(n, 1), f(n);
  M[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      M[j + 1] = (M[j] + M[j + 1]) % MOD;
      M[j] = (LL)M[j] * (MOD - x[i]) % MOD;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      if (i != j) {
        px[i] = (LL)px[i] * (x[i] - x[j] + MOD) % MOD;
      }
  }
  for (int i = 0; i < n; ++i) {
    LL t = (LL)y[i] * inv(px[i]) % MOD, k = M[n];
    for (int j = n - 1; j >= 0; --j) {
      f[j] = (f[j] + k * t) % MOD;
      k = (M[j] + k * x[i]) % MOD;
    }
  }
  return f;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> mat(n, std::vector<int>(n));
  std::vector<int> y(n + 1), x(n + 1);
  for (int x = 0; x <= n; x++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mat[i][j] = 0;
      }
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j) {
        int v = a[i][j] == '0' ? 0 : a[i][j] == '1' ? 1 : x;
        mat[i][j] = mat[j][i] = v ? P - v : 0;
        mat[i][i] = (mat[i][i] + v) % P;
        mat[j][j] = (mat[j][j] + v) % P;
      }
    y[x] = detP(n - 1, mat);
    // std::cerr << y[x] << ' ';
  }
  // std::cerr << '\n';
  std::iota(x.begin(), x.end(), 0);
  const auto f = lagrange_interpolation(x, y);
  // for (auto i : f) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  Z ans = 0;
  for (int i = 1; i <= q; i++) {
    int a, b;
    Z res = 0;
    std::cin >> a >> b;
    Z k = Z(a) / Z(b);
    for (int i = n; i >= 0; i--) {
      res = res * k + f[i];
    }
    ans += res * i;
    // std::cerr << res << '\n';
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