#include <bits/stdc++.h>
#define int long long

void solve() {
  int N, M, n, m;
  std::cin >> N >> M >> n >> m;
  int w = std::gcd(N - n, M - m);
  w = std::gcd(w, N);
  w = std::gcd(w, M);
  std::cout << w << '\n';
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