#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> L(n + 1), R(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> L[i] >> R[i];
  }
  auto work = [&](auto self, int l, int r, int x) -> int {
    if (l == r) {
      return L[l] <= x && x <= R[l] ? x + 1 : x;
    }
    int mid = (l + r) / 2;
    int y = self(self, l, mid, x);
    return self(self, mid + 1, r, y);
  };
  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << work(work, 1, n, x) << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}