#include <bits/stdc++.h>
#define int long long

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
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<std::array<int, 3>>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int m;
    std::cin >> m;
    for (int j = 1; j <= m; j++) {
      int x, y, z;
      std::cin >> x >> y >> z;
      a[i].push_back({x, y, z});
    }
  }
  int seed;
  std::cin >> seed;

  std::mt19937 rng(seed);
  std::uniform_int_distribution<> u(1, 400);

  auto solve = [&](int iq, int eq, int aq) {
    int ans = 0;
    auto ask = std::array<int, 3>{iq, eq, aq};
    for (int i = 1; i <= n; i++) {
      for (auto x : a[i]) {
        if (x[0] <= iq && x[1] <= eq && x[2] <= aq) {
          ans++;
          break;
        }
      }
    }
    return ans;
  };

  int lastans = 0, ans = 0;
  for (int i = 1; i <= q; i++) {
    int IQ = (u(rng) ^ lastans) % 400 + 1; // The IQ of the i-th friend
    int EQ = (u(rng) ^ lastans) % 400 + 1; // The EQ of the i-th friend
    int AQ = (u(rng) ^ lastans) % 400 + 1; // The AQ of the i-th friend
    lastans = solve(IQ, EQ, AQ);           // The answer to the i-th friend
    // std::cout << IQ << ' ' << EQ << ' ' << AQ << ' ' << lastans << '\n';
    ans += lastans * qpow(seed, q - i);
    ans %= mod;
  }
  std::cout << ans << '\n';
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