#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main(signed argc, char **argv) {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::mt19937 rd(std::random_device{}());

  int n = 2e5, m = 1e2, mod = 998244353;
  std::cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n; i++) {
    int l = rd() % m + 1, r = rd() % m + 1;
    if (l > r) std::swap(l, r);
    int p = rd() % mod, q = rd() % mod;
    if (p > q) std::swap(p, q);
    std::cout << l << ' ' << r << ' ';
    std::cout << p << ' ' << q << '\n';
  }

  return 0;
}