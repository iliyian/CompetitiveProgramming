// date: 2025-03-19 22:34:01
// tag: 可以用基数排序，但是还是暴力用二分+字符串哈希找第一个不同的位置然后手动淘汰更好，跑得很快，这题挺有意思，关键复杂度也对

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
 
bool isprime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int findPrime(int n) {
  while (!isprime(n)) {
    n++;
  }
  return n;
}
std::mt19937 rd(std::random_device{}());
// constexpr u32 P = findPrime(rd() % (int)(9e8) + (int)1e8);
constexpr u32 P = 1111111121;
using Z = ModInt<P>;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  std::vector<Z> p(m * 2 + 1);
  std::vector<std::vector<Z>> h(n + 1, std::vector<Z>(m * 2 + 1));
  auto get = [&](int i, int l, int r) {
    Z x = h[i][r] - h[i][l - 1] * p[r - l + 1];
    if (x < 0) x += P;
    return x;
  };
  p[0] = 1;
  for (int i = 1; i <= m * 2; i++) {
    p[i] = p[i - 1] * 2;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i] + a[i];
    for (int j = 1; j <= m * 2; j++) {
      h[i][j] = h[i][j - 1] * 2 + (a[i][j] - '0');
    }
  }
  std::stack<int> s;
  for (int i = 1; i <= m; i++) {
    assert(s.empty());
    for (int j = 1; j <= n; j++)  {
      s.push(j);
    }
    while (s.size() > 1) {
      int u = s.top(); s.pop();
      int v = s.top(); s.pop();
      int l = i, r = i + m - 1, ans = 0;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (get(u, i, mid) != get(v, i, mid)) {
          ans = mid, r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      // assert(ans != -1);
      // if (ans == -1) {
      //   std::cerr << i << ' ' << u << ' ' << v << ' ' << a[u] << ' ' << a[v] << '\n';
      //   continue;
      // }
      // std::cerr << i << ' ' << u << ' ' << v << ' ' << ans << ' ' << a[u][ans] << ' ' << a[v][ans] << '\n';
      if (a[u][ans] > a[v][ans]) s.push(u);
      else s.push(v);
    }
    std::cout << s.top() << ' ';
    s.pop();
  }
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