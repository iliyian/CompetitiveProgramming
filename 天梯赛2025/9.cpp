#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::string ops = "+-*/";
  auto solve = [&](auto self, int l, int r) -> void {
    int cnt = 0;
    if (str[l] != '(') {
      for (int i = l; i <= r; i++) {
        std::cout << str[i];
      }
      return;
    }
    for (int i = l; i <= r; i++) {
      if (str[i] == '(') cnt++;
      if (str[i] == ')') cnt--;
      if (ops.find(str[i]) != ops.npos && cnt == 1) {
        if (str[l + 1] == '(' && str[r - 1] == ')') {
          self(self, l + 1, i - 1);
          self(self, i + 1, r - 1);
          std::cout << str[i] << '\n';
        }
        if (str[l + 1] == '(' && str[r - 1] != ')') {
          self(self, l + 1, i - 1);
          std::cout << str[i];
          self(self, i + 1, r - 1);
          std::cout << '\n';
        }
        if (str[l + 1] != '(' && str[r - 1] == ')') {
          self(self, i + 1, r - 1);
          self(self, l + 1, i - 1);
          std::cout << str[i] << '\n';
        }
        if (str[l + 1] != '(' && str[r - 1] != ')') {
          self(self, l + 1, i - 1);
          std::cout << str[i];
          self(self, i + 1, r - 1);
          std::cout << '\n';
        }
        return;
      }
    }
  };
  solve(solve, 1, n);
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