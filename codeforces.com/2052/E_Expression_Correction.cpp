// date: 2025-01-24 17:22:23
// tag: 模拟

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  auto eval = [](std::string str) {
    int prv = -1;
    int ans = 0;
    // std::cerr << std::format("eval:({})", str) << '\n';
    for (int i = 0; i <= str.size(); i++) {
      if (i == str.size() || !isdigit(str[i])) {
        if (i - prv - 1 > 10 || prv == str.size() - 1 || !isdigit(str[prv + 1]) || (str[prv + 1] == '0' && i - prv - 1 > 1)) {
          // std::cerr << "eval fail\n";
          return LLONG_MIN;
        }
        std::string num = str.substr(prv + 1, i - prv - 1);
        ans += stoll(num) * (prv == -1 || str[prv] == '+' ? 1 : -1);
        prv = i;
      }
    }
    // std::cerr << std::format("eval to:({})", ans) << '\n';
    return ans;
  };
  auto check = [&](std::string &str) {
    // std::cerr << std::format("check:({})", str) << '\n';
    int x = str.find('=');
    auto l = eval(str.substr(0, x));
    auto r = eval(str.substr(x + 1, str.size() - x - 1));
    if (l == LLONG_MIN || r == LLONG_MIN) return false;
    if (l != r) return false;
    return true;
  };
  if (check(str)) {
    std::cout << "Correct\n";
    return;
  }
  int n = str.size();
  for (int i = 0; i < n; i++) {
    if (isdigit(str[i])) {
      auto ch = str[i];
      str.erase(str.begin() + i);
      // std::cerr << std::format("erased:({})", str) << '\n';
      for (int j = 0; j <= n; j++) {
        if (j == n) {
          str.push_back(ch);
        } else {
          str.insert(str.begin() + j, ch);
        }
        if (check(str)) {
          std::cout << str << '\n';
          return;
        }
        if (j == n) {
          str.pop_back();
        } else {
          str.erase(str.begin() + j);
        }
      }
      str.insert(str.begin() + i, ch);
    }
  }
  std::cout << "Impossible\n";
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