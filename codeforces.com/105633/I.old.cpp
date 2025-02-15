#include <algorithm>
#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> fac(N + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    int t = a[i];
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        fac[j].push_back(i);
        if (j * j != a[i]) {
          fac[a[i] / j].push_back(i);
        }
      }
    }
  }
  // std::set<int> s;
  std::vector<int> vec;
  int tot = 0;
  for (int i = 1; i <= N; i++) {
    std::sort(fac[i].begin(), fac[i].end());
    if (fac[i].size() > 1) {
      // s.insert(i);
      vec.push_back(i);
      tot += fac[i].size();
    }
  }
  // std::cerr << vec.size() << '\n';
  int q;
  std::cin >> q;
  std::map<int, int> mp;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int id = (l - 1) * n + r - 1;
    if (mp.count(id)) {
      std::cout << mp[id] << '\n';
      continue;
    }
    for (int i = vec.size() - 1; i >= 0; i--) {
      int &x = vec[i];
      auto p = std::lower_bound(fac[x].begin(), fac[x].end(), l) - fac[x].begin();
      if (p == fac[x].size() || p == fac[x].size() - 1 || fac[x][p + 1] > r) {
        continue;
      }
      std::cout << x << '\n';
      // mp[id] = x;
      break;
    }
  }
  std::cerr << tot << '\n';
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