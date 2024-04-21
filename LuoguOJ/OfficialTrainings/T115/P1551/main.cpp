#include <bits/stdc++.h>
using namespace std;

int fa[5010];

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  int n, m, p, cnt = 0;
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    int fx = find(x), fy = find(y);
    fa[find(x)] = find(y);
    // 如果 fa[find(x)] = y，则stakoverflow;
  }
  for (int i = 0; i < p; i++) {
    int x, y;
    cin >> x >> y;
    if (find(x) == find(y)) {
      cout << "Yes\n";
    } else cout << "No\n";
  }
  return 0;
}