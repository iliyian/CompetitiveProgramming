#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

struct Node {
  int l, r, idx;
  bool operator < (const Node &b) const {
    return std::tie(l, b.r) < std::tie(b.l, r);
  }
  bool operator == (const Node &b) const {
    return std::tie(l, r) == std::tie(b.l, b.r);
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<Node> a(n + 1);
  std::vector<int> vec = {INT_MIN};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].l >> a[i].r;
    vec.push_back(a[i].l);
    vec.push_back(a[i].r);
    a[i].idx = i;
  }
  std::sort(vec.begin(), vec.end());
  auto id = [&](int x) {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };

  int len = vec.size() - 1;
  std::vector<int> mx(len << 2, INT_MIN);
  auto modify = [&](auto self, int x, int s, int t, int p, int c) {
    if (x > t || x < s) return;
    if (s == t) {
      mx[p] = std::max(mx[p], c);
      return;
    }
    self(self, x, s, mid, lc, c);
    self(self, x, mid + 1, t, rc, c);
    mx[p] = std::max(mx[lc], mx[rc]);
  };

  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l > t || r < s) return INT_MIN;
    if (l <= s && t <= r) return mx[p];
    return std::max(self(self, l, r, s, mid, lc), self(self, l, r, mid + 1, t, rc));
  };

  std::sort(a.begin() + 1, a.end());
  
  std::vector<int> ansl(n + 1, INT_MIN), ansr(n + 1, INT_MAX);
  std::vector<int> ok(n + 1, 1);

  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      ok[a[i].idx] = ok[a[i - 1].idx] = false;
    }
  }

  std::multiset<int> s;
  for (int i = 1; i <= n; i++) {
    auto [l, r, idx] = a[i];
    auto p = s.lower_bound(r);
    if (p != s.end()) {
      ansr[idx] = std::min(ansr[idx], *p);
      int j = id(*p);
      auto x = query(query, j, len, 1, len, 1);
      if (x >= 1 && x <= len) {
        ansl[idx] = std::max(ansl[idx], vec[x]);
      }
    } else {
      ok[idx] = false;
    }
    s.insert(r);
    modify(modify, id(r), 1, len, 1, id(l));
  }
  std::sort(a.begin() + 1, a.end(), [&](const Node &x, const Node &y) {
    return x.idx < y.idx;
  });
  for (int i = 1; i <= n; i++) {
    if (!ok[i]) {
      std::cout << 0 << ' ';
    } else {
      std::cout << a[i].l - ansl[i] + ansr[i] - a[i].r << ' ';
    }
    // std::cout << ' ';
    // std::cout << ansl[i] << ' ' << ansr[i] << " \n"[i == n];
  }
  std::cout << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}