// date: 2024-03-17 18:19:06
// tag: 扩展欧拉定理，递归
// wa#01: 没考虑到每次递归的2的幂的模数也会随递归层数不断改变

#include <bits/stdc++.h>
#define int long long
#define N 10000005
using namespace std;

vector<int> pri, phi(N);
bitset<N> vis;

void solve() {
  int p;
  cin >> p;
  int a = 1;
  auto qpow = [](int a, int b, int p) {
    int ans = 1;
    while (b) {
      if (b & 1) ans = ans * a % p;
      a = a * a % p;
      b >>= 1;
    }
    return ans;
  };
  int pre = 1, ans = 0;
  auto dfs = [&qpow](auto self, int p) -> int {
    if (p == 1) return 0;
    return qpow(2, self(self, phi[p]) % phi[p] + phi[p], p);
  };
  cout << dfs(dfs, p) << '\n';
} 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  for(int i = 2; i <= 10000000; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      phi[i] = i - 1;
    }
    for (int p : pri) {
      if (i * p > 10000000) break;
      vis[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
    }
  }

  while (_--) {
    solve();
  }

  return 0;
}