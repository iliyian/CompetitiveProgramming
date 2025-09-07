#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  std::array<std::set<std::pair<int, int>>, 2> s;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    s[0].insert({a[i], i});
    s[1].insert({a[i] ^ k, i});
  }
  for (int i = 1; i <= n - 1; i++) {
    auto [v, idx] = *s[i & 1].begin();
    if (i % 2) {
      s[0].erase({a[idx], idx});
      s[1].erase(s[1].begin());
    } else {
      s[1].erase({a[idx] ^ k, idx});
      s[0].erase(s[0].begin());
    }
  }
  std::cout << s[n & 1 ^ 1].begin()->first << '\n';
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