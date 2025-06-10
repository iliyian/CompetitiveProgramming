#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  if (str.front() != str.back()) {
    std::cout << "empty\n";
    return;
  }
  for (int i = 2; i < n; i++) {
    if (str[i] == str[i - 1] && str[i] != str.front()) {
      std::cout << "empty\n";
      return;
    }
  }
  int len = 1, ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    if (i == n || str[i] != str.front()) {
      ans = std::min(ans, len);
      len = 0;
    } else {
      len++;
    }
  }
  for (int i = 0; i < ans; i++) {
    std::cout << str.front();
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