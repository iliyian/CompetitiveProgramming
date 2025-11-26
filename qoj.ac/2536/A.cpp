#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;
std::vector<int> bucket;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    bucket[a[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int g = 0;
    if (bucket[i]) continue;
    for (int j = i; j <= N; j += i) {
      if (bucket[j]) {
        g = std::gcd(g, j / i);
      }
    }
    if (g == 1) {
      ans++;
    }
  }
  // std::cerr << ans << '\n';
  std::cout << (ans % 2 ? "dXqwq" : "Haitang") << '\n';
  for (int i = 1; i <= n; i++) {
    bucket[a[i]]--;
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  bucket.assign(N + 1, 0);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}