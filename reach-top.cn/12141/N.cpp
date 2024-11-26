#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<int> pri, vis(N + 1);

void solve() {
  int n;
  std::cin >> n;
  if (vis[n]) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 0;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}