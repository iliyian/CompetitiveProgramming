// date: 2024/02/05 21:12:55
// tag: 01trie，
// wa#01: cnt初始值应该为1,这样才能变成2,而不是一开始就是0

// tot初始值为1是为了特殊情况下trie[u][0|1]=0后trie[0][0|1]=0;
// 避免干扰正常数据

// 以及多测只清空cnt和val即可，因为tot本身不携带具体信息
// 仅仅在trie上存自己和val的索引

#include <bits/stdc++.h>
#define N 100005
using namespace std;

struct Edge {
  int v, w;
};
vector<vector<Edge>> g;

// 2**31
int ch[N << 5][2], cnt = 1, ans = 0, dis[N];

void add(int x) {
  for (int i = 30, u = 1; i >= 0; i--) {
    int c = ((x >> i) & 1);
    if (!ch[u][c]) ch[u][c] = ++cnt;
    u = ch[u][c];
  }
}

void query(int x) {
  int res = 0;
  for (int i = 30, u = 1; i >= 0; i--) {
    int c = ((x >> i) & 1);
    if (ch[u][c ^ 1]) {
      u = ch[u][c ^ 1];
      res |= 1 << i;
    } else {
      u = ch[u][c];
    }
  }
  ans = max(ans, res);
}

void dfs(int u, int prv) {
  add(dis[u]);
  query(dis[u]);
  for (auto [v, w] : g[u]) {
    if (v == prv) continue;
    dis[v] = dis[u] ^ w;
    dfs(v, u);
  }
}

void solve() {
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w}), g[v].push_back({u, w});
  }
  dfs(1, 0);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}