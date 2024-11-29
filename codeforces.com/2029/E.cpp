#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<int> pri, low(N + 1, -1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int i = 1;
  while (i <= n && low[a[i]] != -1) i++;
  if (i == n + 1) {
    std::cout << 2 << '\n';
    return;
  }
  for (int j = 1; j <= n; j++) {
    if (i == j) continue;
    if (low[a[j]] == -1) {
      std::cout << -1 << '\n';
      // std::cout << a[j] << '\n';
      return;
    }
    if (a[j] < a[i]) {
      // std::cerr << a[j] << '\n';
      std::cout << -1 << '\n';
      return;
    }
    if (a[j] % a[i] == 0) continue;
    if (a[j] <= a[i] * 2 + 1) {
      std::cout << -1 << '\n';
      return;
    }
    if (a[j] - pri[low[a[j]]] < a[i] * 2) {
      // std::cerr << pri[low[a[j]]] << '\n';
      std::cout << -1 << '\n';
      return;
    }
  }
  std::cout << a[i] << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  for (int i = 2; i <= N; i++) {
    if (low[i] == -1) {
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] > N) break;
      low[i * pri[j]] = j;
      if (i % pri[j] == 0) {
        break;
      }
    }
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}