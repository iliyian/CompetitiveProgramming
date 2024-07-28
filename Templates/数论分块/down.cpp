// date: 2024-07-28 14:01:10
// tag: mobius反演，数论分块

#include <bits/stdc++.h>
#define int long long
// using namespace std

constexpr int N = 5e4;

std::vector<int> pri, vis(N + 1), mo(N + 1), d(N + 1), num(N + 1);

void solve() {
  int n, m;
  std::cin >> n >> m;
  int ans = 0;
  for (int i = 1, j; i <= std::min(n, m); i = j + 1) {
    j = std::min(n / (n / i), m / (m / i));
    ans += d[n / i] * d[m / i] * (mo[j] - mo[i - 1]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  mo[1] = d[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      mo[i] = -1;
      num[i] = 1;
      d[i] = 2;
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) {
        num[i * p] = num[i] + 1;
        d[i * p] = d[i] / num[i * p] * (num[i * p] + 1);
        mo[i * p] = 0;
        break;
      }
      mo[i * p] = -mo[i];
      d[i * p] = d[i] * 2;
      num[i * p]  = 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    d[i] += d[i - 1];
    mo[i] += mo[i - 1];
  }

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}