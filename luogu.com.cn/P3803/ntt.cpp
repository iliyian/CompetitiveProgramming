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

void ntt(std::vector<Z> &a, bool op) {
  int len = 1, L = 0;
  while (len < a.size()) len <<= 1, L++;
  a.resize(len);
  std::vector<int> tr(len);
  for (int i = 0; i < len; i++) {
    tr[i] = (tr[i >> 1] >> 1) | ((i & 1) << (L - 1));
    if (i < tr[i]) {
      std::swap(a[i], a[tr[i]]);
    }
  }
  for (int h = 2; h <= len; h <<= 1) {
    Z wn = power(op ? 3 : power(Z(3), P - 2), (P - 1) / h);
    for (int i = 0; i < len; i += h) {
      Z w = 1;
      for (int j = i; j < i + h / 2; j++, w *= wn) {
        Z t = w * a[j + h / 2];
        a[j + h / 2] = a[j] - t;
        a[j] = a[j] + t;
      }
    }
  }
  if (op == 0) {
    Z inv = power(Z(len), P - 2);
    for (int i = 0; i < len; i++) {
      a[i] *= inv;
    }
  }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  n++, m++;
  std::vector<Z> a(n), b(m);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a[i] = x;
  }
  for (int i = 0; i < m; i++) {
    int x;
    std::cin >> x;
    b[i] = x;
  }
  int len = n + m - 1;
  a.resize(len), b.resize(len);
  ntt(a, 1);
  ntt(b, 1);
  for (int i = 0; i < a.size(); i++) {
    a[i] *= b[i];
  }
  ntt(a, 0);
  for (int i = 0; i < n + m - 1; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
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