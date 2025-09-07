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
  std::vector<int> ans(n + 1);
  auto p = std::upper_bound(primes.begin(), primes.end(), n) - primes.begin() - 1;
  for (int i = p; i >= 0; i--) {
    if (primes[i] * 2 > n) {
      ans[primes[i]] = primes[i];
    } else {
      std::vector<int> pos;
      for (int j = primes[i]; j <= n; j += primes[i]) {
        if (ans[j] == 0) {
          pos.push_back(j);
        }
      }
      for (int j = 0; j < pos.size(); j++) {
        ans[pos[(j + 1) % pos.size()]] = pos[j];
      }
    }
  }
  ans[1] = 1;
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  sieve((int)1e5 + 10);

  while (t--) {
    solve();
  }

  return 0;
}