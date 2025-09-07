#include <bits/stdc++.h>
#define int long long

using u64 = unsigned long long;

constexpr int N = 5e6;
std::vector<int> minp, primes, ans(N + 1), pos(N + 1);
std::vector<u64> val(N + 1);

std::mt19937_64 rd(std::random_device{}());

void sieve(int n) {
  minp.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (!minp[i]) {
      minp[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (i * p > n) break;
      minp[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::cout << ans[n] << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve(N);
  for (int i = 2; i <= N; i++) {
    int x = i, v = 1;
    while (x > 1) {
      int y = minp[x];
      while (x % y == 0) x /= y;
      v *= y;
    }
    // ans[v]++;
    if (!pos[v]) {
      pos[v] = i;
      ans[v]++;
    }
  }
  for (int i = 2; i <= N; i++) {
    ans[i] += ans[i - 1];
  }
  // std::cerr << s.size() << '\n';

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}