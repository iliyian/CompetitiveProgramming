#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> busy(n + 1), vis(n + 1);
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    busy[x] = true;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!busy[i]) {
      vis[i] = 1;
      q.push(i);
      break;
    }
  }
  std::vector<std::vector<int>> ans;
  int cnt = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ans.push_back({});
    bool f = false;
    for (int v : g[u]) {
      if (!vis[v]) {
        ans.back().push_back(v);
        cnt++;
        f = true;
        // std::cout << v << ' ';
        if (!busy[v]) {
          q.push(v);
        }
        vis[v] = true;
      }
    }
    if (!f) {
      ans.pop_back();
      continue;
    }
    ans.back().push_back(u);
  }
  if (cnt != n - 1) {
    std::cout << "No\n";
    // std::cout << cnt << '\n';
    return;
  }
  std::cout << "Yes\n";
  std::cout << ans.size() << '\n';
  for (auto &v : ans) {
    std::cout << v.back() << ' ';
    std::cout << v.size() - 1 << ' ';
    for (int i = 0; i < v.size() - 1; i++) {
      std::cout << v[i] << ' ';
    }
    std::cout << '\n';
  }
}

signed main() 
{
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t=1;
  //std::cin >> t;
  while (t--) 
  {
    solve();
  }
  return 0;
}