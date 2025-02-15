#include <bits/stdc++.h>
#define int long long

constexpr int mod = 998244353;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::multiset<int> a, b;
  int as = 0, bs = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    as += x;
    a.insert(x);
  }
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    bs += x;
    b.insert(x);
  }
  if (as != bs) {
    std::cout << "No\n";
    return;
  }
  // for (auto v : a) {
  //   std::cout << v << ' ';
  // }
  // std::cout << '\n';
  // for (auto v : b) {
  //   std::cout << v << ' ';
  // }
  if (a.empty() && b.empty()) {
    std::cout << "Yes\n";
    return;
  }
  if (a.empty() || b.empty()) {
    std::cout << "No\n";
    return;
  }
  if (a.size() * 2 < b.size()) {
    std::cout << "No\n";
    return;
  }
  auto get = [&](this auto &&self, int x) -> bool {
    if (a.count(x)) {
      a.erase(a.find(x));
      return true;
    }
    if (x == 1) return false;
    return self((x + 1) / 2) && self(x / 2);
  };
  // for (auto v : a) {
  //   std::cout << v << ' ';
  // }
  // std::cout << '\n';
  // for (auto v : b) {
  //   std::cout << v << ' ';
  // }
  // std::cout << '\n';
  for (auto v : b) {
    if (!get(v)) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}