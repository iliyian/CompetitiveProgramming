// date: 2025-05-29 19:35:26
// tag: 感觉是很经典的某个结论：max(maxcnt, (n + 1) / 2)。但是这种先假设全部取max一端，然后修正的做法，还是比较妙的

#include <bits/stdc++.h>
#define int long long

using namespace std;

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

struct Comb {
  int n;
  vector<Z> _fac, _inv;
  Comb() : _fac{1}, _inv{0} {}
  Comb(int n) : Comb() { init(n); }
  void init(int m) {
    if (m <= n)
      return;
    _fac.resize(m + 1);
    _inv.resize(m + 1);
    for (int i = n + 1; i <= m; i++) {
      _fac[i] = _fac[i - 1] * i;
    }
    _inv[m] = _fac[m].inv();
    for (int i = m; i > n; i--) {
      _inv[i - 1] = _inv[i] * i;
    }
    n = m;
  }
  Z fac(int x) {
    if (x > n)
      init(x);
    return _fac[x];
  }
  Z inv(int x) {
    if (x > n)
      init(x);
    return _inv[x];
  }
  Z C(int x, int y) {
    if (x < 0 || y < 0 || x < y)
      return 0;
    return fac(x) * inv(y) * inv(x - y);
  }
  Z P(int x, int y) {
    if (x < 0 || y < 0 || x < y)
      return 0;
    return fac(x) * inv(x - y);
  }
} comb(1 << 21);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> mp;
  Z ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mp[a[i]]++;
    ans += comb.C(n, i) * ((i + 1) / 2);
  }
  for (auto [k, v] : mp) {
    for (int i = 1; i <= v; i++) {
      for (int j = 0; j <= i - 1; j++) {
        if (i + j > n) continue;
        ans += comb.C(v, i) * comb.C(n - v, j) * (i - (i + j + 1) / 2);
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