// date: 2024-03-24 14:46:35
// tag: 树形dp


#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cout << x << ' ';
#else
#define debug(x) ;
#endif

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  string str;
  cin >> n >> str;
  str = '#' + str;
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }

  vector<int> f(n + 1), con(n + 1), pa(n + 1);
  stack<int> st;
  auto dfs = [&](auto self, int u) -> void {
    for (int v : g[u]) {
      pa[v] = u;
      int t = 0;
      if (str[v] == ')' && !st.empty()) {
        int x = st.top(); st.pop();
        con[v] = con[pa[x]] + 1;
        t = x;
      }
      f[v] = f[u] + con[v];
      if (str[v] == '(') st.push(v);
      self(self, v);
      if (str[v] == '(') st.pop();
      if (t) st.push(t);
    }
  };
  if (str[1] == '(') st.push(1);
  dfs(dfs, 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    debug(f[i]);
    ans ^= i * f[i];
  }
  debug('\n');
  cout << ans << '\n';

  return 0;
}