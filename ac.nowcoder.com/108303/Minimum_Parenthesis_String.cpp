#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string str(n * 2, '?');
  std::vector<std::pair<int, int>> b(m);
  std::vector<int> v;
  for (int i = 0; i < m; i++) {
    auto &[l, r] = b[i];
    std::cin >> l >> r;
    l--, r--;
  }
  std::ranges::sort(b | std::views::reverse);
  std::set<int> s;
  int cnt = n;
  for (auto [l, r] : b) {
    auto p = s.lower_bound(l);
    if (p != s.end() && *p <= r) continue;
    s.insert(l);
    str[l] = '(';
    cnt--;
  }
  // std::cout << str << '\n';
  for (int i = 0; i < n * 2; i++) {
    if (cnt > 0 && str[i] == '?') {
      str[i] = '(';
      cnt--;
    }
  }
  // std::cout << str << '\n';
  for (int i = 0; i < n * 2; i++) {
    if (str[i] == '?') {
      str[i] = ')';
    }
  }
  int sum = 0;
  for (int i = 0; i < n * 2; i++) {
    sum += (str[i] == '(' ? 1 : -1);
    if (sum < 0) {
      std::cout << -1 << '\n';
      return;
    }
  }
  if (sum != 0) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << str << '\n';
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