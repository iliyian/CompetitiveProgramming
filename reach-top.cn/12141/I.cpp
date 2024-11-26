#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e4;

std::vector<int> pri, vis(N + 1);

void solve() {
  int n;
  while (std::cin >> n, n) {
    for (int i = n / 2; i >= 2; i--) {
      if (!vis[i] && !vis[n - i]) {
        std::cout << i << ' ' << n - i << '\n';
        break;
      }
    }
  }
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