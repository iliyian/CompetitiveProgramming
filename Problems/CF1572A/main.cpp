// date: 2024-03-26 17:17:37
// tag: 带优先队列的拓扑排序

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

struct Node {
  int x, t;
  bool operator < (const Node &b) const {
    return t == b.t ? x > b.x : t > b.t;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int x;
      cin >> x;
      g[x].push_back(i);
      in[i]++;
    }
  }
  priority_queue<Node> q;
  int tot = 1;
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      q.push({i, 1});
    }
  }
  vector<int> ans(n + 1, inf);
  while (!q.empty()) {
    auto [x, t] = q.top(); q.pop();
    ans[x] = t;
    for (int y : g[x]) {
      if (!--in[y]) {
        q.push({y, t + (y < x)});
      }
    }
  }
  int res = *max_element(ans.begin() + 1, ans.end());
  cout << (res == inf ? -1 : res) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}