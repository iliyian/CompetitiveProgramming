// date: 2024-11-12 22:07:35
// tag: 贪心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::vector<int> a(n + 1), raw(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    raw[i] = a[i];
  }
  std::vector<int> x(m + 1), t(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> x[i] >> t[i];
  }
  std::vector<int> nxt(m + 1), pos(n + 1, m + 1);
  for (int i = m; i >= 1; i--) {
    nxt[i] = pos[t[i]];
    pos[t[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    q.push({pos[i], i});
  }
  int curstation = 1, nowpos = 0;
  while (!q.empty()) {
    auto [idx, id] = q.top(); q.pop();
    int d;
    if (curstation <= m && a[id] >= (d = x[curstation] - nowpos)) {
      a[id] -= d;
      nowpos = x[curstation];
      a[t[curstation]] = raw[t[curstation]];
      q.push({nxt[curstation], t[curstation]});
      if (id != t[curstation]) {
        q.push({idx, id});
      }
      curstation++;
    } else {
      nowpos += a[id];
      a[id] = 0;
    }
  }
  std::cout << nowpos << '\n';
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