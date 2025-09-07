#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> t(n + 1), f(n + 1);
  std::vector<std::array<int, 3>> a;
  for (int i = 1; i <= n; i++) {
    std::cin >> t[i] >> f[i];
    a.push_back({t[i], 1, f[i]});
  }
  std::vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    int x;
    std::cin >> x;
    a.push_back({x, 2, i});
  }
  std::ranges::sort(a);
  std::queue<int> que;
  int flag = 0;
  for (auto [tm, op, x] : a) {
    if (op == 1) {
      if ()
    } else {

    }
  }
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