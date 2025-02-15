#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<std::vector<int>> fac(N + 1);

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  // std::vector<std::vector<int>> pos(N + 1);
  std::vector<int> cnt(N + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (auto j : fac[a[i]]) {
      // pos[j].push_back(i);
      cnt[j]++;
    }
  }
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = fac[a[i]].size() - 1; j >= 0; j--) {
      if (cnt[fac[a[i]][j]] >= k) {
        ans[i] = fac[a[i]][j];
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << '\n';
  }
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