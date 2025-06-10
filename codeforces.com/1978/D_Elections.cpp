// date: 2025-03-31 21:30:42
// tag: 小模拟，贪心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n + 1), mx(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[i] = std::max(mx[i - 1], a[i] + (i == 1 ? c : 0));
    s[i] = s[i - 1] + a[i];
  }
  std::vector<int> ans;
  for (int i = n; i >= 1; i--) {
    if (mx[i - 1] != mx[i] && mx[n] == a[i]) {
      // std::cout << 0 << ' ';
      ans.push_back(0);
      continue;
    }
    int sum = s[i - 1];
    if (sum + a[i] + c < mx[n]) {
      // std::cout << i << ' ';
      ans.push_back(i);
    } else {
      // std::cout << i - 1 << ' ';
      ans.push_back(i - 1);
    }
  }
  for (auto i : ans | std::views::reverse) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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