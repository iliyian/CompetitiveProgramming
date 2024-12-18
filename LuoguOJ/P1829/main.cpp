// date: 2024-07-27 22:36:59
// tag: mobius，数论分块

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 20101009;

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

int inv(int a) {
  return qpow(a, mod - 2);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  auto h = [&](int n, int m) {
    return n * (n + 1) % mod * inv(2) % mod * m % mod * (m + 1) % mod * inv(2) % mod;
  };

  int N = std::min(n, m);
  std::vector<int> mo(N + 1), pri, vis(N + 1);
  mo[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      mo[i] = -1;
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) {
        mo[i * p] = 0;
        break;
      }
      mo[i * p] = -mo[i];
    }
  }
  for (int i = 1; i <= N; i++) {
    mo[i] = (mo[i - 1] + mo[i] * i % mod * i % mod) % mod;
  }

  auto sum = [&](int n, int m) -> int {
    int ans = 0;
    for (int i = 1, j; i <= std::min(n, m); i = j + 1) {
      j = std::min(n / (n / i), m / (m / i));
      ans += ((mo[j] - mo[i - 1]) % mod + mod) % mod * h(n / i, m / i) % mod;
      ans %= mod;
    }
    return ans;
  };

  int ans = 0;
  for (int i = 1, j = 1; i <= std::min(n, m); i = j + 1) {
    j = std::min(n / (n / i), m / (m / i));
    ans += (i + j) % mod * (j - i + 1) % mod * inv(2) % mod * sum(n / i, m / i) % mod;
    ans %= mod;
  }
  std::cout << ans << '\n';

  return 0;
}