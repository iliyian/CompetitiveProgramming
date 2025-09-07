// date: 2025-07-13 20:07:21
// tag: 

#include <bits/stdc++.h>
#define int long long

std::vector<int> minp, primes;
std::vector<std::vector<int>> fac((int)5e5 + 10);

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
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto &d = fac[m];
  int len = d.size();
  std::vector<std::vector<int>> da(len, std::vector<int>(n + 2));
  std::vector<int> cnt(len);
  for (int i = 0; i < len; i++) {
    for (int j = 1; j <= n; j++) {
      da[i][j] = a[j] % d[i];
      cnt[i] += da[i][j] < da[i][j - 1];
    }
    da[i][n + 1] = LLONG_MAX;
  }
  while (q--) {
    int op, x;
    std::cin >> op >> x;
    if (op == 1) {
      int y;
      std::cin >> y;
      for (int i = 0; i < len; i++) {
        if (da[i][x] < da[i][x - 1]) {
          cnt[i]--;
        }
        if (da[i][x + 1] < da[i][x]) {
          cnt[i]--;
        }
        da[i][x] = y % d[i];
        if (da[i][x] < da[i][x - 1]) {
          cnt[i]++;
        }
        if (da[i][x + 1] < da[i][x]) {
          cnt[i]++;
        }
      }
    } else {
      int g = std::gcd(x, m);
      int p = std::lower_bound(d.begin(), d.end(), g) - d.begin();
      // std::cerr << cnt[p] * g + da[p][n] << '\n';
      std::cout << (cnt[p] * g + da[p][n] < m ? "YES" : "NO") << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  sieve((int)5e5 + 10);
  for (int i = 1; i <= (int)5e5; i++) {
    for (int j = i; j <= (int)5e5; j += i) {
      fac[j].push_back(i);
    }
  }

  while (t--) {
    solve();
  }

  return 0;
}
