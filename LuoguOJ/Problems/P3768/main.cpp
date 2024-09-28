#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int mod, n;
  std::cin >> mod >> n;

  std::vector<int> pri, minp(n + 1, -1), phi(n + 1), cub(n + 1);
  cub[1] = phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    cub[i] = cub[i - 1] + i * i % mod * i % mod;
    cub[i] %= mod;
    if (minp[i] == -1) {
      minp[i] = pri.size();
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int j = 0; j < pri.size(); j++) {
      if (i * pri[j] > n) break;
      minp[i * pri[j]] = j;
      if (i % pri[j] == 0) {
        phi[i * pri[j]] = phi[i] * pri[j];
        break;
      }
      phi[i * pri[j]] = phi[i] * phi[pri[j]]; // 积性
    }
  }

  for (int i = 1; i <= n; i++) {
    phi[i] *= i * i % mod;
    phi[i] %= mod;
  }

  for (int i = 1; i <= n; i++) {
    phi[i] += phi[i - 1];
    phi[i] %= mod;
  }

  int ans = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    j = n / (n / i);
    ans += ((phi[j] - phi[i - 1]) % mod + mod) % mod * cub[n / i] % mod;
    ans %= mod;
  }
  std::cout << ans << '\n';

  return 0;
}