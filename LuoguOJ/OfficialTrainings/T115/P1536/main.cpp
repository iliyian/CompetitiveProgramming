// 集合数量等于根节点数量

#include <bits/stdc++.h>
using namespace std;

int fa[1001];

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      fa[find(u)] = find(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (find(i) == i) ans++;
    cout << ans - 1 << '\n';
  }
  return 0;
}