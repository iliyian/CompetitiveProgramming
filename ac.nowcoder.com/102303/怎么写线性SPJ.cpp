#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> ans;
  std::set<int> s;
  int t = 1;
  while (ans.size() < n) {
    auto tmp = ans;
    ans.push_back(t++);
    ans.insert(ans.end(), tmp.begin(), tmp.end());
  }
  for (auto i : ans) s.insert(i);
  std::cout << s.size() << '\n';
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}