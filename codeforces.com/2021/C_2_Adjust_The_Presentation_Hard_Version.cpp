// date: 2025-01-31 14:30:49
// tag: 动态维护点，根据常见的单点修改维护相邻偏序之类的关系时，最多修改两个相邻地方的性质来低于O(n)时间复杂度的修改
// 也是常见的维护set
// 但是本题区别在于，周围集合为空时要特殊处理，哎
// 果然不能忽视任何一个地方，有可能就是没有着重看的地方出了错误

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, Q;
  std::cin >> n >> m >> Q;
  std::vector<int> a(n + 1), b(m + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]] = i;
  }
  std::set<int> bad;
  std::vector<std::set<int>> q(n + 2);
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    b[i] = pos[b[i]];
    q[b[i]].insert(i);
  }
  for (int i = 2; i <= n; i++) {
    if (!q[i].empty() && (q[i - 1].empty() || *q[i - 1].begin() > *q[i].begin())) {
      // 注意到必然是个排列，所以只需要看连续的就好了，又他妈审题不清了
      // bad.insert(*q[i].begin());
      bad.insert(i);
    }
  }
  // for (auto i : bad) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  std::cout << (bad.empty() ? "YA" : "TIDAK") << '\n';

  auto update = [&](int x) {
    bool f = false;
    if (x > 1 && x <= n && (q[x].empty() || !q[x - 1].empty() && *q[x - 1].begin() < *q[x].begin())) {
      bad.erase(x);
      f = true;
    }
    if (x > 1 && x <= n && !q[x].empty() && (q[x - 1].empty() || *q[x - 1].begin() > *q[x].begin())) {
      bad.insert(x);
      assert(!f);
    }
  };

  while (Q--) {
    int s, t;
    std::cin >> s >> t;
    t = pos[t];

    int old = b[s];
    q[old].erase(s);
    update(old);
    update(old + 1);

    b[s] = t;
    q[t].insert(s);
    update(t);
    update(t + 1);

    std::cout << (bad.empty() ? "YA" : "TIDAK") << '\n';

    // for (auto i : bad) {
    //   std::cerr << i << ' ';
    // }
    // std::cerr << '\n';
  }
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