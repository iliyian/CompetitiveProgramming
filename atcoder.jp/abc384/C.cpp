#include <bits/stdc++.h>
#define int long long

void solve() {
  std::array<int, 5> a;
  for (int i = 0; i < 5; i++) {
    std::cin >> a[i];
  }
  std::vector<std::pair<int, std::string>> vec;
  for (int i = 1; i < 32; i++) {
    std::string name = "";
    int score = 0;
    for (int j = 0; j < 5; j++) {
      if (i >> j & 1) {
        name.push_back('A' + j);
        score += a[j];
      }
    }
    vec.push_back({-score, name});
  }
  std::sort(vec.begin(), vec.end());
  for (auto [_, name] : vec) {
    std::cout << name << '\n';
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
