#include <bits/stdc++.h>
#define int long long

void solve() {
  std::vector<std::array<int, 3>> a(8);
  for (int i = 0; i < 8; i++) {
    std::cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  std::vector<double> v = {0};
  auto d = [&](int x, int y) {
    return (x - y) * (x - y);
  };
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++) {
      v.push_back(d(a[i][0], a[j][0]) + d(a[i][1], a[j][1]) + d(a[i][2], a[j][2]));
    }
  }
  std::sort(v.begin() + 1, v.end());
  if (v[1] == 0) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 2; i <= 12; i++) {
    if (v[i] != v[1]) {
      std::cout << "NO\n";
      return;
    }
  }
  for (int i = 14; i <= 24; i++) {
    if (v[i] != v[13]) {
      std::cout << "NO\n";
      return;
    }
  }
  for (int i = 26; i <= 28; i++) {
    if (v[i] != v[25]) {
      std::cout << "NO\n";
      return;
    }
  }
  if (2 * v[1] != v[13]) {
    std::cout << "NO\n";
    return;
  }
  if (3 * v[1] != v[25]) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
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