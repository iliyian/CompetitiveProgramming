#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  int h = 0;
  // std::vector<std::set<int>> s(n + 5);
  std::vector<std::vector<int>> s(n + 5);
  std::vector<std::vector<int>> g;
  std::multiset<int> ms;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ms.insert(x);
  }
  int tot = 0;
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n * 2; i++) {
    if (str[i] == '(') {
      h++;
      ++tot;
      // s[h].insert(tot);
      s[h].push_back(tot);
    } else {
      h--;
      g.push_back(s[h + 2]);
      s[h + 2].clear();
    }
  }
  g.push_back(s[1]);
  int len = g.size();
  std::vector<int> p(len);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](const int &x, const int &y) {
    return g[x].size() > g[y].size();
  });
  for (int i = 0; i < len; i++) {
    auto x = ms.begin();
    for (int j : g[p[i]]) {
      // std::cerr << j << ' ';
      if (x == ms.end()) {
        std::cout << "NO\n";
        return;
      }
      ans[j] = *x;
      int old = *x;
      x = ms.erase(x);
      if (*x == old) x = ms.upper_bound(*x);
    }
    // std::cerr << '\n';
  }
  std::cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
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