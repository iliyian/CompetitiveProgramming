// date: 2025-05-15 22:12:29
// tag: 绷不住了，怎么n*n都要取模啊？这是真tmd难查。顺便games确实有意思

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

constexpr int mod = 998244353;
 
int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mp[a[i]] += 1;
  }
  std::vector<std::array<int, 2>> tr(n * 32);
  std::vector<int> cnt(n * 32 + 1);
  int tot = 1;
  auto insert = [&](int x, int v) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!tr[u][idx]) tr[u][idx] = ++tot;
      u = tr[u][idx];
      cnt[u] += v;
    }
  };
  int ans = 0, den = qpow(n * n % mod, mod - 2);
  // Z ans = 0, den = Z(n * n).inv();
  // double ans = 0, den = 1.0 / (n * n);
  for (auto [k, v] : mp) {
    insert(k, v);
    // ans += (__builtin_popcountll(k) + 1) * (v * v % mod) % mod * den % mod;
    ans += den * (__builtin_popcountll(k) + 1) % mod * v % mod * v % mod;
    // ans += (__builtin_popcountll(k) + 1) * v * v * den;
    ans %= mod;
  }
  auto query = [&](int x, int v) {
    int u = 1, pop = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      pop += idx;
      // ans += (pop + 1) * (v * cnt[tr[u][idx ^ 1]] % mod) % mod * den % mod;
      ans += den * (pop + 1) % mod * v % mod * cnt[tr[u][idx ^ 1]] % mod;
      // ans += (pop + 1) * v * cnt[tr[u][idx ^ 1]] * den;
      ans %= mod;
      u = tr[u][idx];
    }
  };
  for (auto [k, v] : mp) {
    query(k, v);
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