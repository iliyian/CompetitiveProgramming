// date: 2024-08-17 16:57:49
// tag: 筛法，欧拉函数

// g[n]=\sum_{i=1}^{i<n}{gcd(i,n)}=\sum_{d|n}d\phi(n/d), g[1]=1
// 积性函数的狄利克雷卷积同样为奇函数

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e6;

std::vector<int> phi(N + 1), pri, minp(N + 1), low(N + 1), g(N + 1), cnt(N + 1);

void solve(int n) {
  std::cout << (g[n] - n * (n + 1) / 2) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  g[1] = phi[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!minp[i]) {
      pri.push_back(i);
      minp[i] = low[i] = i;
      phi[i] = i - 1;
      g[i] = i * 2 - 1;
      cnt[i] = 1;
    }
    for (int p : pri) {
      if (i * p > N) break;
      minp[i * p] = p;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        low[i * p] = low[i] * p;
        if (low[i] == i) { // i == p^k
          cnt[i * p] = cnt[i] + 1;
          g[i * p] = (cnt[i * p] + 1) * i * p - cnt[i * p] * i;
        } else { // 
          g[i * p] = g[i / low[i]] * g[p * low[i]];
        }
        break;
      } // 积性函数
      low[i * p] = p;
      phi[i * p] = phi[i] * (p - 1);
      g[i * p] = g[i] * g[p];
    }
  }

  for (int i = 1; i <= N; i++) {
    g[i] += g[i - 1];
  }

  int n;
  while (std::cin >> n && n) {
    solve(n);
  }

  return 0;
}