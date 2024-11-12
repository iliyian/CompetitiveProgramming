#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  int start = -1;
  std::map<int, int> ans, cnt;
  std::vector<std::map<int, bool>> done(n + 1);
  for (int i = 1; i <= k; i++) {
    int typ, id, x;
    std::cin >> typ;
    if (typ == 1) {
      std::cin >> x;
      start = x;
    } else if (typ == 2) {
      std::cin >> id >> x;
      if (x != start) continue;
      if (!done[x][id]) {
        done[x][id] = true;
        ans[id] += m - cnt[x];
        cnt[x]++;
      }
    } else {
      std::cin >> id >> x;
      if (x != start) continue;
      if (!done[x][id]) {
        done[x][id] = true;
      }
    }
  }
  std::vector<int> vis(m + 1);
  std::vector<std::pair<int, int>> vec;
  for (auto &[k, v] : ans) {
    // std::cout << k << ' ' << v << '\n';
    vec.push_back({v, -k});
    vis[k] = true;
  }
  std::sort(vec.begin(), vec.end(), std::greater<>());
  for (auto &[v, k] : vec) {
    std::cout << -k << ' ' << v << '\n';
  }
  for (int i = 1; i <= m; i++) {
    if (!vis[i]) {
      std::cout << i << ' ' << 0 << '\n';
    }
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