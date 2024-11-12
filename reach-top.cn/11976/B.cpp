#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

// 这tmd都筛法了n才160就离谱

std::vector<int> pri, vis(N + 1);

void solve() {
  int n;
  std::cin >> n;
  for (int p : pri) {
    if (p > n) break;
    std::cout << p << '\n';
  }
}

signed main() {

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
  while (t--) {
    solve();
  }
  return 0;
}