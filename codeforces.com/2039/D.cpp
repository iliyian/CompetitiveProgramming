// date: 2024-11-29 21:35:56
// tag: gcd性质，构造

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

std::vector<int> pri, low(N + 1, -1);
std::vector<std::vector<int>> pos(N + 1);

std::vector<std::vector<int>> fac(N + 1);

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  std::reverse(a.begin() + 1, a.end());
  std::vector<int> ans(n + 1);
  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    int mx = INT_MIN;
    for (int f : fac[i]) {
      mx = std::max(mx, ans[f]);
    }
    if (mx + 1 > m) {
      std::cout << -1 << '\n';
      return;
    }
    ans[i] = mx + 1;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[ans[i]] << ' ';
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  for (int i = 2; i <= N; i++) {
    if (low[i] == -1) {
      pri.push_back(i);
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] >= N) break;
      low[i * pri[j]] = j;
      if (i % pri[j] == 0) break;
    }
  }
  for (int i = 2; i <= N; i++) {
    if (low[i] == -1) continue;
    pos[low[i]].push_back(i);
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}