// date: 2024-04-22 14:26:58
// tag: 哈希，分治，dp

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n + 1);
  vector<array<int, 2>> h(10000, {0, 0});
  
  auto getn = [&](int l, int len, string &s) {
    if (l + len > s.size()) return 0;
    return stoi(s.substr(l, len)) * 10 + len;
  };

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int l = 0; l + 2 <= m; l++) {
      h[getn(l, 2, a[i])] = {l, i};
      if (l + 3 <= m) {
        h[getn(l, 3, a[i])] = {l, i};
      }
    }
  }
  string str;
  cin >> str;
  vector<array<array<int, 2>, 2>> f(max(m, 3));

  f[1][0] = h[getn(0, 2, str)];
  f[2][1] = h[getn(0, 3, str)];

  for (int i = 3; i < m; i++) {
    if (f[i - 2][0][1] || f[i - 2][1][1]) {
      f[i][0] = h[getn(i - 1, 2, str)];
    }
    if (f[i - 3][0][1] || f[i - 3][1][1]) {
      f[i][1] = h[getn(i - 2, 3, str)];
    }
  }
  deque<array<int, 3>> ans;
  int cur = m - 1;
  while (cur != -1 && (f[cur][0][1] || f[cur][1][1])) {
    if (f[cur][1][1]) {
      ans.push_front({3, f[cur][1][0], f[cur][1][1]});
      cur -= 3;
    } else {
      ans.push_front({2, f[cur][0][0], f[cur][0][1]});
      cur -= 2;
    }
  }
  if (cur != -1) {
    cout << -1 << '\n';
    return;
  }
  cout << ans.size() << '\n';
  for (auto [len, l, i] : ans) {
    cout << l + 1 << ' ' << l + len << ' ' << i << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}