#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<std::vector<int>> fac(N + 1);

int solve(int x, int k) {
  if (x == 1) return 0;
  int n = fac[x].size();
  std::vector<int> f(n, LLONG_MAX / 3);
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (fac[x][j] % fac[x][i] == 0 && fac[x][j] / fac[x][i] <= k) {
        f[j] = std::min(f[i] + 1, f[j]);
      }
    }
  }
  return f[n - 1] == LLONG_MAX / 3 ? -1 : f[n - 1];
}

void solve() {
  int x, y, k;
  std::cin >> x >> y >> k;
  int g = std::gcd(x, y);
  x /= g, y /= g;
  int ans1 = solve(x, k), ans2 = solve(y, k);
  if (ans1 == -1 || ans2 == -1) {
    std::cout << -1 << '\n';
  } else {
    std::cout << ans1 + ans2 << '\n';
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
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}