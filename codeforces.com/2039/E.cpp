#include <bits/stdc++.h>
#define int long long

std::vector<std::set<std::vector<int>>> s(100);

void dfs(std::vector<int> cur) {
  s[cur.size()].insert(cur);
  if (cur.size() == 7) {
    return;
  }
  int inv = 0;
  for (int i = 0; i < cur.size(); i++) {
    for (int j = i + 1; j < cur.size(); j++) {
      inv += cur[i] > cur[j];
    }
  }
  auto tmp = cur;
  for (int i = 0; i <= cur.size(); i++) {
    tmp.insert(tmp.begin() + i, inv);
    dfs(tmp);
    tmp.erase(tmp.begin() + i);
  }
}

void solve() {
  dfs({0, 1});
  for (auto i : s[5]) {
    for (auto j : i) {
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }
  for (int i = 2; i <= 7; i++) {
    std::cout << s[i].size() << ' ';
  }
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