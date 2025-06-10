#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    std::array<int, 3> a, p;
    std::cin >> a[0] >> a[1] >> a[2];
    p = {0, 1, 2};
    std::set<int> ok;
    do {
      if ((a[p[2]] - a[p[1]]) % a[p[0]] == 0) {
        auto t = (a[p[2]] - a[p[1]]) / a[p[0]];
        if (t >= 0) {
          ok.insert((a[p[2]] - a[p[1]]) / a[p[0]]);
        }
      }
    } while (std::next_permutation(p.begin(), p.end()));
    if (i == 1) {
      s = ok;
    } else {
      auto t = s;
      for (auto x : t) {
        if (ok.find(x) == ok.end()) {
          s.erase(x);
        }
      }
    }
  }
  std::cout << *s.begin() << '\n';
  assert(s.size() == 1);
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