#include <bits/stdc++.h>
#define int long long

void solve() {
  int h, w, n;
  std::cin >> h >> w >> n;
  std::vector<std::set<int>> r(h + 1), c(w + 1);
  std::vector<std::pair<int, int>> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> pos[i].first >> pos[i].second;
    r[pos[i].first].insert(i);
    c[pos[i].second].insert(i);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int op, x;
    std::cin >> op >> x;
    if (op == 1) {
      std::cout << r[x].size() << '\n';
      for (auto i : r[x]) {
        c[pos[i].second].erase(i);
      }
      r[x].clear();
    } else {
      std::cout << c[x].size() << '\n';
      for (auto i : c[x]) {
        r[pos[i].first].erase(i);
      }
      c[x].clear();
    }
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