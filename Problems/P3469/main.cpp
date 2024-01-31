// date: 2024/01/31 15:42:48
// tag: wa#01,割点和割边的求法不仅在于>变成>=，还在于v->u，且有两个入口
// tmd求有序数对，在计算siz两两乘积和的时候忘记*2了，这也是三个地方中唯一忘记的
// 不是双连通分量，更类似于割点的应用
// 至于oi-wiki上面用差分判断点双连通...什么鬼

#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

vector<vector<int>> g;
int dfn[N], low[N], cnt = 0, siz[N], ans[N], n, m;
bitset<N> ins, isCutPt, vis;
stack<int> st;

void tarjan(int u, int prv) {
  dfn[u] = low[u] = ++cnt;
  int sum = 0;
  siz[u] = 1;
  for (int v : g[u]) {
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      siz[u] += siz[v];
      if (low[v] >= dfn[u] && prv || (g[u].size() >= 2 && !prv)) {
        // 不适用于起始点
        // 顺便这和割边不一样，那是v，这是u
        // isCutPt[u] = true;
        // 类似于前缀和的思想了

        // tmd *2
        ans[u] += siz[v] * sum * 2;
        sum += siz[v];
      }
    // 由于全部连通只有一个stack
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
  // 独木成森
  ans[u] += (n - 1) * 2;
  // 自然，sum会=0
  ans[u] += (n - 1 - sum) * sum * 2;
}

void solve() {
  cin >> n >> m;
  g.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  // 这是全部连通
  tarjan(1, 0);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}