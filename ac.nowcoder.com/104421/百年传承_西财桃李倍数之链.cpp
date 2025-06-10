#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;
constexpr int mod = 1e9 + 7;

std::vector<std::vector<int>> fac(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int cnt = 1;
    for (auto j : fac[a[i]]) {
      cnt += mp[j];
      cnt %= mod;
    }
    mp[a[i]] += cnt;
    mp[a[i]] %= mod;
  }
  int ans = 0;
  for (auto [k, v] : mp) {
    ans += v;
    ans %= mod;
    // std::cerr << k << ' ' << v << '\n';
  }
  std::cout << ans - n << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}