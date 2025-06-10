// date: 2025-03-23 10:26:26
// tag: 最nb的一次，补到了div2F，很经典的结论，要让所有数靠在一起，必定是向中间的两个数（偶数）或一个数（奇数）移动，不会更劣
// 然后根据结论反推，枚举可以作为中间的，然后判断是否存在合法的两边，此时必定是当前作为mid时的最优解

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> pos(k + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]].push_back(i);
  }
  int ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    std::vector<int> l, r;
    for (int j = 1; j <= k; j++) {
      if (j != a[i]) {
        auto p = std::lower_bound(pos[j].begin(), pos[j].end(), i) -
                 pos[j].begin() - 1;
        auto q =
            std::upper_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
        if (p == -1)
          r.push_back(pos[j][q]);
        else if (q == pos[j].size())
          l.push_back(pos[j][p]);
        else {
          if (i - pos[j][p] < pos[j][q] - i) {
            l.push_back(pos[j][p]);
          } else {
            r.push_back(pos[j][q]);
          }
        }
      }
    }
    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());
    int ldis = 0, rdis = 0;
    for (int j = l.size() - 1; j >= 0; j--) {
      ldis += i - l[j] - (l.size() - j);
    }
    for (int j = 0; j < r.size(); j++) {
      rdis += r[j] - i - (j + 1);
    }
    if (std::abs((int)l.size() - (int)r.size()) <= 1) {
      ans = std::min(ans, ldis + rdis);
    }
  }
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