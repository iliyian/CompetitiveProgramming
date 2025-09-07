#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  int a = std::stoll(s, 0, 2);
  int b = std::stoll(t, 0, 2);
  char op;
  std::cin >> op;
  if (op == '+') {
    std::cout << a + b << '\n';
  } else if (op == '-') {
    std::cout << a - b << '\n';
  } else if (op == '*') {
    std::cout << a * b << '\n';
  } else {
    std::cout << a / b << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}