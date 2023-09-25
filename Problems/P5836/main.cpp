// awesome

#include <bits/stdc++.h>
using namespace std;

int pa[100001];
char color[100001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1 ;i <= n; i++)
    cin >> color[i], pa[i] = i;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    if (color[u] == color[v])
      pa[find(u)] = find(v);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    if (find(x) == find(y) && color[x] != c) cout << 0;
    else cout << 1;
  }
  return 0;
}