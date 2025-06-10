#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int prv = 1;
  std::vector<std::array<int, 2>> a;
  for (int i = 2; i <= n + 1; i++) {
    if (i == n + 1 || str[i] != str[i - 1]) {
      a.push_back({prv, i - 1});
      prv = i;
    }
  }
  int ans = 0;
  if (std::count(str.begin() + 1, str.end(), '1')) {
    ans++;
  }
  auto getl = [&](int i) {
    auto [l, r] = a[i];
    return (l - 1) * (r - l + 1) + (r - l + 1) * (r - l) / 2;
  };
  auto getr = [&](int i) {
    auto [l, r] = a[i];
    return (n - r) * (r - l + 1) + (r - l + 1) * (r - l) / 2;
  };
  for (int i = (str[1] == '1'); i < a.size(); i += 2) {
    auto [l, r] = a[i];
    ans = std::max(ans, getl(i));
    ans = std::max(ans, getr(i));
    if (i - 1 >= 0) {
      ans = std::max(ans, getl(i) + 1);
    }
    if (i + 1 < a.size()) {
      ans = std::max(ans, getr(i) + 1);
    }
    if (i - 2 >= 0 && a[i - 1][0] == a[i - 1][1]) { // 向左合并
      ans = std::max(ans, getr(i - 2) + getl(i) + 1);
    }
    if (i + 2 < a.size() && a[i + 1][0] == a[i + 1][1]) {
      ans = std::max(ans, getr(i) + getl(i + 2) + 1);
    }
    // std::cerr << ans << '\n';
  }
  std::cout << ans << '\n';
  // std::cerr << '\n';
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     std::cerr << char(str[j] ^ (i == j));
  //   }
  //   std::cerr << '\n';
  // }
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