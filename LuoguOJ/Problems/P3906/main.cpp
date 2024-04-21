// floyd 神中神

#include <bits/stdc++.h>
using namespace std;

int a[41][41];

struct Node {
  int u, d;
};
queue<Node> q;

int dis, n, m;

void floyd() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      a[i][j] = 1 << 29;
    a[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = a[v][u] = 1;
  }
  int k;
  cin >> k;
  floyd();
  set<int> s;
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    int d = a[u][v];
    for (int j = 1; j <= n; j++)
      if (a[u][j] + a[j][v] == d)
        s.insert(j);
    for (auto j : s)
      cout << j << ' ';
    cout << '\n';
    s.clear();
  }
  return 0;
}