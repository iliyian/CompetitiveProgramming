// date: 2025-01-28 17:41:33
// tag: 模拟，二分套线段树上二分，考虑只有两条分界线，动态维护一条分界线的同时找到第二条分界线的可能值使得满足二分条件
// 突破口在于只需要分成四块，于是可以嵌套着做，在一维使用暴力的前提下，另一维便可以用通过线段树找到区间区间前k大所在的位置之类的，然后外面再利用答案的连续性

#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  std::vector<int> vec = {INT_MIN};
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    vec.push_back(x);
    vec.push_back(y);
    a[i] = {x, y};
  }
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  auto id = [&](int x) {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  int len = vec.size() - 1;
  std::vector<std::vector<int>> nodes(len + 1);
  for (int i = 1; i <= n; i++) {
    nodes[id(a[i].second)].push_back(id(a[i].first));
  }
  std::vector<int> dl(len << 2), dr(len << 2);
  auto add = [&](auto self, std::vector<int> &d, int x, int s, int t, int p, int c) {
    if (x > t || x < s) return;
    if (s == t) {
      d[p] += c;
      return;
    }
    self(self, d, x, s, mid, lc, c);
    self(self, d, x, mid + 1, t, rc, c);
    d[p] = d[lc] + d[rc];
  };
  // 最小的s，使得d中小于等于x的数量大于等于x
  // 至少为0
  auto queryl = [&](auto self, std::vector<int> &d, int s, int t, int p, int x) {
    if (s == t) return s;
    if (d[lc] >= x) return self(self, d, s, mid, lc, x);
    return self(self, d, mid + 1, t, rc, x - d[lc]);
  };
  auto queryr = [&](auto self, std::vector<int> &d, int s, int t, int p, int x) {
    if (s == t) return s;
    if (d[rc] >= x) return self(self, d, mid + 1, t, rc, x);
    return self(self, d, s, mid, lc, x - d[rc]);
  };
  auto querysum = [&](auto self, std::vector<int> &d, int s, int t, int p, int x) -> int {
    if (x < s) return 0;
    if (s == t) return d[p];
    return self(self, d, s, mid, lc, x) + self(self, d, mid + 1, t, rc, x);
  };
  auto clear = [&](int ssh) {
    for (int i = 1; i <= len; i++) {
      for (auto j : nodes[i]) {
        add(add, i < ssh ? dl : dr, j, 1, len, 1, -1);
      }
    }
  };
  auto check = [&](int mi, bool f) -> bool {
    for (int i = 1; i <= len; i++) {
      for (int j : nodes[i]) {
        // int x = vec[j];
        add(add, dr, j, 1, len, 1, 1);
      }
    }
    for (int i = 1; i <= len; i++) {
      int ll = queryl(queryl, dl, 1, len, 1, mi) + 1;
      int lr = queryr(queryr, dl, 1, len, 1, mi);
      int rl = queryl(queryl, dr, 1, len, 1, mi) + 1;
      int rr = queryr(queryr, dr, 1, len, 1, mi);
      // std::cerr << (querysum(querysum, dl, 1, len, 1, ll)) << '\n';
      // ll += (querysum(querysum, dl, 1, len, 1, ll) == mi);
      // rl += (querysum(querysum, dr, 1, len, 1, rl) == mi);
      // std::cerr << mi << ' ' << i << ' ' << ll << ' ' << lr << ' ' << rl << ' ' << rr << '\n';
      // std::cerr << ll << ' ' << lr << ' ' << rl << ' ' << rr << '\n';
      if (!(lr < rl || rr < ll) && ll <= lr && rl <= rr && dl[1] >= mi * 2 && dr[1] >= mi * 2) {
        // std::cerr << mi << ' ' << i << ' ' << ll << ' ' << lr << ' ' << rl << ' ' << rr << '\n';
        if (f) {
          std::cout << vec[std::max(ll, rl)] << ' ' << vec[i] << '\n';
        }
        clear(i);
        return true;
      }
      for (int j : nodes[i]) {
        // int x = vec[j];
        add(add, dr, j, 1, len, 1, -1);
        add(add, dl, j, 1, len, 1, 1);
      }
    }
    clear(len + 1);
    return false;
  };
  int l = 0, r = n / 4, ans = -1;
  while (l <= r) {
    int mi = (l + r) / 2;
    // std::cerr << "mi: " << mi << '\n';
    if (check(mi, false)) l = mi + 1, ans = mi;
    else r = mi - 1;
    // std::cerr << '\n';
  }
  if (ans == -1) {
    std::cout << 0 << '\n' << 0 << ' ' << 0 << '\n';
    return;
  }
  std::cout << ans << '\n';
  check(ans, true);
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