// date: 2024-05-21 17:27:38
// tag: 图的遍历，字符串

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e6)
#define mod 998244353
using namespace std;

vector<int> g[N + 5];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("L.in", "r", stdin);
  freopen("L.out", "w", stdout);

  string str;
  cin >> str;

  int tot = 0;
  stack<int> s;
  vector<pair<int, int>> p;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '(') {
      s.push(i);
    } else {
      int tp = s.top(); s.pop();
      if (tp == i - 1) {
        p.push_back({tp, ++tot});
      } else {
        ++tot;
        while (!p.empty() && p.back().first >= tp) {
          g[tot].push_back(p.back().second);
          p.pop_back();
        }
        p.push_back({tp, tot});
      }
    }
  }
  int rt = ++tot;
  for (auto [pos, val] : p) {
    g[rt].push_back(val);
  }

  vector<int> a;
  auto dfs = [&](auto self, int u) -> void {
    sort(g[u].begin(), g[u].end());
    for (int v : g[u]) {
      self(self, v);
    }
    a.push_back(u);
  };
  dfs(dfs, rt);
  int ans = 1;
  for (int i = 0; i < a.size(); i++) {
    if (!g[a[i]].empty() && a[i] != rt) {
      ans = ans * (a.size() - i - 1) % mod;
    }
  }
  cout << ans << '\n';
  // for (auto i : a) {
  //   cerr << i << ' ';
  // }

  return 0;
}