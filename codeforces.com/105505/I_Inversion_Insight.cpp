#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<int> a(3);
  std::iota(a.begin(), a.end(), 1);
  std::vector<std::pair<int, std::vector<int>>> b;

  do {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
      for (int j = i + 1; j < a.size(); j++) {
        ans += a[i] > a[j];
      }
    }
    // for (int i = 0; i < a.size(); i++) {
    //   std::cout << a[i] << ' ';
    // }
    // std::cout << ' ' << ans << '\n';
    b.push_back({ans, a});
  } while (std::next_permutation(a.begin(), a.end()));
  std::sort(b.begin(), b.end());
  for (auto &[x, y] : b) {
    for (auto i : y) {
      std::cout << i << ' ';
    }
    std::cout << x << '\n';
  }

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}