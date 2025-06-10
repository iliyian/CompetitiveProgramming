#include <bits/stdc++.h>
#define int long long

void solve() {
  std::map<int, int> mp;
  for (int i = 0; i < 7; i++) {
    int x;
    std::cin >> x;
    mp[x]++;
  }
  bool f = false, g = false;
  std::vector<int> vec;
  for (auto [k, v] : mp) {
    vec.push_back(v);
  }
  std::sort(vec.begin(), vec.end());
  for (int i : vec) {
    if (i >= 2) {
      if (!f) f = true;
      else if (i >= 3 && !g) g = true;
    }
  }
  std::cout << (f && g ? "Yes" : "No") << '\n';
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