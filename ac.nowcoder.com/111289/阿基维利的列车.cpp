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
  int n, k;
  std::cin >> n >> k;
  k++;
  for (int i = 1; i <= n; i++) {
    std::cout << primes[(i - 1) % k] * primes[k + i - 1] << '\n';
    // std::cout << primes[(i - 1) % k] << ',' << primes[k + i - 1] << ' ';
    // if (i % k == 0) {
    //   std::cout << '\n';
    // }
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  sieve((int)1e7);
  // std::cerr << primes.back() << '\n';

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}