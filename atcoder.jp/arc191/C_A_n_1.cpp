// date: 2025-01-31 17:24:58
// tag: 什么神仙的二项式定理 (n+1)^k=\sum_{i=0}^{k}{C_{k}^{i}n^i}=1+\sum_{i=1}^{k}{C_{k}^{i}n^i}
// \equiv kn \mod n^2，大于等于2的没了，零也没了，只有一次了，什么神仙妙妙
// 所以 k 最小为 n，什么神仙构造

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::cout << n + 1 << ' ' << n * n << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}