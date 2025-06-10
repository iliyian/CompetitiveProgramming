// date: 2025-04-08 11:42:34
// tag: 数论题，经典的和给定的情况下，不同数的数量不超过根号的结论

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::multiset<int> s;
  int cnt0 = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
  }
  while (s.size() > 1) {
    // for (auto i : s) {
    //   std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
    std::multiset<int> t;
    int prv = -1;
    for (auto i : s) {
      if (prv != -1) {
        if (i == prv) {
          cnt0++;
        } else {
          t.insert(i - prv);
        }
      }
      prv = i;
    }
    s = t;
    if (cnt0) {
      cnt0--;
      s.insert(0);
    }
  }
  std::cout << *s.begin() << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}