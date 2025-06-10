#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

constexpr int mod = 1e9 + 7;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  // std::vector<std::pair<int, int>> vec;
  std::vector<std::vector<int>> vecl(n + 1);
  int l = 1;
  std::set<int> sl;
  std::priority_queue<std::pair<int, int>> qg;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> ql;
  int pl = 0, pr = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      l = i;
      vecl[i].push_back(l);
      while (!ql.empty()) ql.pop();
      while (!qg.empty()) qg.pop();
      sl.clear();
      continue;
    }
    if (i > 2) {
      if (a[i - 2] >= a[i - 1] && a[i - 1] > a[i] || a[i - 2] <= a[i - 1] && a[i - 1] < a[i]) {
        l = i - 1;
        while (!ql.empty()) ql.pop();
        while (!qg.empty()) qg.pop();
        sl.clear();
        sl.insert(i - 1);
        if (a[i] > a[i - 1]) {
          qg.push({a[i - 1], i - 1});
        } else {
          ql.push({a[i - 1], i - 1});
        }
      }
      sl.insert(i);
      int mx = 0;
      if (a[i] > a[i - 1]) {
        ql.push({a[i], i});
        while (!qg.empty() && qg.top().first >= ql.top().first) {
          sl.erase(qg.top().second);
          mx = std::max(mx, qg.top().second);
          qg.pop();
        }
      } else {
        qg.push({a[i], i});
        while (!ql.empty() && ql.top().first <= qg.top().first) {
          sl.erase(ql.top().second);
          mx = std::max(mx, ql.top().second);
          ql.pop();
        }
      }
      while (!sl.empty() && *sl.begin() < mx) {
        sl.erase(sl.begin());
      }
      l = *sl.begin();
    } else {
      sl.insert(l);
      sl.insert(i);
      if (a[i] > a[i - 1]) {
        ql.push({a[i], i});
        qg.push({a[i - 1], i - 1});
      } else {
        qg.push({a[i], i});
        ql.push({a[i - 1], i - 1});
      }
    }
    // if (i == l) continue;
    // vec.push_back({l, i});
    // std::cerr << l << ' ' << i << ' ' << sl.size() << '\n';
    if (pl != l && pl) {
      // std::cerr << pl << ' ' << pr << '\n';
    }
    pl = l, pr = i;
    vecl[i].push_back(l);
  }
  if (pl) {
    // std::cerr << pl << ' ' << pr << '\n';
  }
  std::vector<int> maxr(n << 2), maxlen(n << 2);
  auto query = [&](auto self, int l, int r, int s, int t, int p, std::vector<int> &d) -> int {
    if (l > t || r < s) return 0;
    if (l <= s && t <= r) return d[p];
    return std::max(self(self, l, r, s, mid, lc, d), self(self, l, r, mid + 1, t, rc, d));
  };
  auto add = [&](auto self, int l, int s, int t, int p, int r) {
    if (l > t || l < s) return;
    if (s == t) {
      maxr[p] = std::max(maxr[p], r);
      maxlen[p] = std::max(maxlen[p], r - l + 1);
      return;
    }
    self(self, l, s, mid, lc, r);
    self(self, l, mid + 1, t, rc, r);
    maxr[p] = std::max(maxr[lc], maxr[rc]);
    maxlen[p] = std::max(maxlen[lc], maxlen[rc]);
  };
  std::vector<std::vector<std::pair<int, int>>> ask(n + 1);
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    ask[r].push_back({l, i});
  }
  std::vector<int> ans(q + 1);
  for (int r = 1; r <= n; r++) {
    for (auto l : vecl[r]) {
      add(add, l, 1, n, 1, r);
    }
    for (auto [l, idx] : ask[r]) {
      if (l == r) {
        ans[idx] = 1;
        continue;
      }
      // std::cerr << l << ' ' << r << ' ' << query(query, 1, l, 1, n, 1, maxr) - l + 1 << ' ' << query(query, l, r, 1, n, 1, maxlen) << '\n';
      ans[idx] = std::max(query(query, 1, l, 1, n, 1, maxr) - l + 1, query(query, l, r, 1, n, 1, maxlen));
    }
  }
  int res = 0;
  for (int i = 1; i <= q; i++) {
    res += i * ans[i] % mod;
    res %= mod;
    // std::cout << ans[i] << '\n';
  }
  std::cout << res << "\n\n";
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