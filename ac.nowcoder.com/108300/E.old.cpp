#include <bits/stdc++.h>
#define int long long

constexpr int N = 5e6;

std::vector<int> minp, primes, cnt;

void sieve(int n) {
  minp.assign(n + 1, 0);
  cnt.assign(n + 1, 0);
  primes.clear();

  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      primes.push_back(i);
    }

    for (auto p : primes) {
      if (i * p > n) {
        break;
      }
      minp[i * p] = p;
      if (p == minp[i]) {
        break;
      }
    }
  }
}

bool isprime(int n) { return minp[n] == n; }

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), vis;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int x = a[i];
    while (x != 1) {
      cnt[minp[x]]++;
      vis.push_back(minp[x]);
      x /= minp[x];
    }
  }
  if (n % 2) {
    std::cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      int x = a[i];
      while (x != 1) {
        cnt[minp[x]]--;
        x /= minp[x];
      }
    }
    return;
  }
  for (int i : vis) {
    if (cnt[i] % 2) {
      std::cout << "NO\n";
      
      for (int i = 1; i <= n; i++) {
        int x = a[i];
        while (x != 1) {
          cnt[minp[x]]--;
          x /= minp[x];
        }
      }
      return;
    }
  }
  std::cout << "YES\n";
  
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x != 1) {
      cnt[minp[x]]--;
      x /= minp[x];
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve(N);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}