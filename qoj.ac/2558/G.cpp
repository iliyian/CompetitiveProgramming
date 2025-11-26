#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) std::cin >> i;
  std::ranges::sort(a);
  auto work = [&]() {
    int s = 0;
    for (auto i : a) {
      if (s >= i) {
        s++;
      } else {
        s--;
      }
    }
    return s;
  };
  std::cout << work() << ' ';
  std::ranges::reverse(a);
  std::cout << work() << '\n';
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