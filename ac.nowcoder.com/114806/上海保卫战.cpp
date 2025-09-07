#include <bits/stdc++.h>
#define int long long

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
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

bool isprime(int n) {
    return minp[n] == n;
}

void solve() {
  int n;
  std::cin >> n;
  for (int i : primes) {
    if (n % i == 0) {
      std::cout << (n - i) / 2 + 2 << '\n';
      return;
    }
  }
  std::cout << 2 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve((int)1e5);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}