// date: 2025-04-23 23:31:28
// tag: 不得不说，很多时候wa，都是自己没有理清所有细节就开始写了。比较清奇的一个数据结构优化dp？顺便可以试试树状数组维护前缀半群信息。

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 2e5;

std::vector<int> d(N << 2);

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s || l > r) return 0;
  if (l <= s && t <= r) return d[p];
  return std::max(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

void modify(int x, int s, int t, int p, int c, bool f) {
  if (x > t || x < s) return;
  if (s == t) {
    d[p] = (f ? c : std::max(d[p], c));
    // d[p] = c;
    return;
  }
  modify(x, s, mid, lc, c, f);
  modify(x, mid + 1, t, rc, c, f);
  d[p] = std::max(d[lc], d[rc]);
}

std::vector<int> f(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 1);
  std::vector<int> mx(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    std::cin >> k;
    for (int j = 1; j <= k; j++) {
      int x;
      std::cin >> x;
      if (x > mx[i]) {
        mx[i] = x;
        a[i].push_back(x);
      }
    }
    p[i] = i;
  }
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return mx[x] < mx[y];
  });
  for (int i = 1; i <= n; i++) {
    auto &v = a[p[i]];
    for (int j = 0; j < v.size(); j++) {
      f[mx[p[i]]] = std::max<int>(f[mx[p[i]]], v.size() - j + query(1, v[j] - 1, 1, N, 1));
    }
    modify(mx[p[i]], 1, N, 1, f[mx[p[i]]], 0);
  }
  int ans = 0;
  for (auto &i : a) {
    for (auto &j : i) {
      ans = std::max(ans, f[j]);
      f[j] = 0;
      // std::cerr << j << ' ' << ans << '\n';
      modify(j, 1, N, 1, 0, 1);
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