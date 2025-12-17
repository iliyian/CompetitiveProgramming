#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  if (std::ranges::count(str, '1') <= k) {
    std::cout << "Alice\n";
    return;
  }
  std::cout << (k > n / 2 ? "Alice" : "Bob") << '\n';
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