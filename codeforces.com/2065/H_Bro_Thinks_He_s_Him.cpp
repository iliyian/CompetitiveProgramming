// date: 2025-02-10 13:48:36
// tag: 朴素dp，性质观察题

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
  int q;
  std::string str;
  std::cin >> str >> q;
  int n = str.size();
  str = '#' + str;
  Z ans = power(Z(2), n) - 1;
  auto add = [&](std::vector<Z> &d, int x, Z c) {
    for (int i = x; i <= n; i += i & -i) d[i] += c;
  };
  auto query = [&](std::vector<Z> &d, int x) {
    Z ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  std::vector<std::vector<Z>> l(2, std::vector<Z>(n + 1)), r(2, std::vector<Z>(n + 1));
  for (int i = 1; i <= n; i++) {
    add(l[str[i] - '0'], i, power(Z(2), i - 1));
  }
  for (int i = n; i >= 1; i--) {
    add(r[str[i] - '0'], i, power(Z(2), n - i));
    ans += power(Z(2), n - i) * query(l[(str[i] - '0') ^ 1], i - 1);
    // std::cerr << ans << ' ' << power(Z(2), n - i) << ' ' << query(l[(str[i] - '0') ^ 1], i - 1) << '\n';
  }
  // std::cerr << '\n';
  // std::cerr << ans << '\n';
  while (q--) {
    int k;
    std::cin >> k;

    ans -= power(Z(2), n - k) * query(l[(str[k] - '0') ^ 1], k - 1)
      + power(Z(2), k - 1) * (query(r[(str[k] - '0') ^ 1], n) - query(r[(str[k] - '0') ^ 1], k));

    add(l[str[k] - '0'], k, -power(Z(2), k - 1));
    add(r[str[k] - '0'], k, -power(Z(2), n - k));
    str[k] ^= 1;
    add(l[str[k] - '0'], k, power(Z(2), k - 1));
    add(r[str[k] - '0'], k, power(Z(2), n - k));
    
    ans += power(Z(2), n - k) * query(l[(str[k] - '0') ^ 1], k - 1)
      + power(Z(2), k - 1) * (query(r[(str[k] - '0') ^ 1], n) - query(r[(str[k] - '0') ^ 1], k));

    std::cout << ans << ' ';
  }
  std::cout << '\n';
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