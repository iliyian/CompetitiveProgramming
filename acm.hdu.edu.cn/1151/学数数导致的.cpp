#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

// std::bitset<N + 1> prvp, prvp0, prvp0p;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  // std::vector<int> prvp0pq(N + 1);
  // std::vector<int> prvp(N + 1), prvp0(N + 1), prvp0p(N + 1);
  // std::set<int> s;
  // prvp.reset();
  // prvp0.reset();
  // prvp0p.reset();
  int ans = 0, cnt = 0;
  std::vector<int> lst(N + 1), visprvp0p(N + 1);
  std::vector<int> prvp, prvp0(N + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    lst[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) {
      if (lst[a[i]] == i) {
        // ans += prvp0p.count();
        // ans += sprvp0p.size();
        ans += cnt;
      }
      if (prvp0[a[i]]) {
        // sprvp0p.insert(a[i]);
        if (!visprvp0p[a[i]]) {
          visprvp0p[a[i]] = 1;
          cnt++;
        }
        // prvp0p[a[i]] = 1;
      }
      // prvp[a[i]] = 1;
      prvp.push_back(a[i]);
    } else {
      for (auto i : prvp) {
        prvp0[i] = 1;
      }
      prvp.clear();
      // prvp0 |= prvp;
    }
    // std::cerr << ans << ' ';
    // if (a[i] == 0) {
    // } else {
    // }
  }
  // for (auto i : s) {
  //   prvp0pq[i] = 0;
  // }
  // std::cerr << '\n';
  std::cout << ans << '\n';
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