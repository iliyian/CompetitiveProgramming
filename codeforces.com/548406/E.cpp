#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  std::vector<std::set<int>> vec;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bool f = false;
    for (auto &s : vec) {
      if (*s.rbegin() != a[i] - 1) {
        s.insert(a[i]);
        f = true;
        break;
      }
    }
    if (!f) {
      vec.push_back({a[i]});
    }
  }
  std::cout << vec.size() << "\n";
}

signed main() {
  freopen("E.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}