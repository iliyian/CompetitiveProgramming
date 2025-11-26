#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;
int a[3][N + 1] {}, cnt[3][N + 1] {};
std::vector<std::vector<int>> re[3];

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> v[3];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      std::cin >> a[j][i];
      cnt[j][a[j][i]]++;
      v[j].push_back(a[j][i]);
      re[j][a[j][i]].push_back(i);
    }
  }
  std::vector<int> dense(n + 1);
  for (int i = 0; i < 3; i++) {
    std::ranges::sort(v[i], [&](auto x, auto y) {
      return cnt[i][x] < cnt[i][y];
    });
    v[i].erase(std::unique(v[i].begin(), v[i].end()), v[i].end());
    for (int j : v[i]) {
      for (int p : re[i][j]) {
        dense[p] = std::max(dense[p], cnt[i][j]);
      }
    }
  }
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    // std::cout << dense[i] << ' ';
    ans[dense[i] - 1]++;
  }
  // std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
  }
  std::cout << 0 << ' ';
  for (int i = 1; i < n; i++) {
    std::cout << ans[i - 1] << ' ';
  }
  std::cout << '\n';
  for (int j = 0; j < 3; j++) {
    v[j].clear();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      cnt[j][a[j][i]]--;
      re[j][a[j][i]].clear();
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 0; i < 3; i++) {
    re[i].assign(N + 1, std::vector<int>());
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}