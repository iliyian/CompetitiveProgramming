#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  if (str[0] != '>') {
    std::cout << "No\n";
    return;
  }
  if (str.substr(str.size() - 3, 3) != ">>>") {
    std::cout << "No\n";
    return;
  }
  if (std::count(str.begin(), str.end(), '-') == 0) {
    std::cout << "No\n";
    return;
  }
  int n = str.size();
  std::cout << "Yes ";
  int r = 0;
  std::vector<std::pair<int, int>> ans;
  for (int i = n - 4; i >= 0; i--) {
    if (str[i] == '-') {
      for (int j = n - 3; j >= i + 1; j--) {
        ans.push_back({1, j + 3});
      }
      r = i;
      break;
    }
  }
  for (int i = 1; i < r; i++) {
    if (str[i] == '>') {
      ans.push_back({i + 1, r + 4 - i});
    }
  }
  std::cout << ans.size() << '\n';
  for (auto [l, r] : ans) {
    std::cout << l << ' ' << r << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}