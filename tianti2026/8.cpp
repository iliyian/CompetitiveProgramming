#include <bits/stdc++.h>
#define int long long

using i128 = __int128;

void solve() {
  int x;
  std::vector<int> a, v = {LLONG_MIN / 3};
  while (std::cin >> x) {
    if (x == -1) break;
    a.push_back(x);
    v.push_back(x);
  }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  auto id = [&](int x) {return std::lower_bound(v.begin(), v.end(), x) - v.begin();};
  for (auto &i : a) {
    i = id(i);
  }
  int n = a.size(), m = v.size() - 1;
  std::vector<std::vector<int>> pos(m + 1);
  for (int i = 0; i < n; i++) {
    pos[a[i]].push_back(i);
  }
  int ans = -1, w = LLONG_MAX / 3;
  int ansb, ansc;
  for (int i = 1; i <= m; i++) {
    int prv = -10;
    bool f = true;
    int b = -1, c = -1;
    for (int j : pos[i]) {
      if (j - prv <= 2) {
        f = false;
        break;
      }
      if (j + 2 >= n) {
        f = false;
        break;
      }
      if (b == -1) {
        b = a[j + 1], c = a[j + 2];
      } else if (b != a[j + 1] || c != a[j + 2]) {
        f = false;
        break;
      }
      prv = j;
    }
    if (!f || pos[i].size() < 2) continue;
    if (pos[i][1] < w) {
      w = pos[i][1];
      ans = v[i];
      ansb = v[a[pos[i].front() + 1]];
      ansc = v[a[pos[i].front() + 2]];
    }
  }
  if (ans == -1) {
    std::cout << "NONE\n";
  } else {
    std::cout << ans << ' ' << ansb << ' ' << ansc << '\n';
  }
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