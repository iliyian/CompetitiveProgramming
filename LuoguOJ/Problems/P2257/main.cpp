// date: 2024-08-23 21:35:15
// tag: 优化枚举项的莫比乌斯反演

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e7;

std::vector<int> minp(N + 1, -1), mo(N + 1), pri, s(N + 1);

void solve() {
  int n, m, ans = 0;
  std::cin >> n >> m;
  for (int i = 1, j; i <= std::min(n, m); i = j + 1) {
    j = std::min(n / (n / i), m / (m / i));
    ans += (n / i) * (m / i) * (s[j] - s[i - 1]);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  mo[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (minp[i] == -1) {
      minp[i] = pri.size();
      pri.push_back(i);
      mo[i] = -1;
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] > N) break;
      minp[i * pri[j]] = j;
      if (i % pri[j] == 0) {
        mo[i * pri[j]] = 0;
        break;
      }
      mo[i * pri[j]] = -mo[i];
    }
  }

  for (int p : pri) {
    for (int j = p; j <= N; j += p) {
      s[j] += mo[j / p];
    }
  }
  for (int i = 1; i <= N; i++) {
    s[i] += s[i - 1];
  }

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}