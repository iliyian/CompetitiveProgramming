#include <bits/stdc++.h>
using namespace std;

int pa[30001], dis[30001], sz[30001];

int find(int x) {
  if (x == pa[x]) return x;
  int k = pa[x];
  pa[x] = find(pa[x]); // recursive before
  dis[x] += dis[k];
  sz[x] = sz[pa[x]];
  return pa[x];
}

int main() {
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  for (int i = 0; i <= 30000; i++) pa[i] = i, sz[i] = 1, dis[i] = 0;
  for (int i = 0; i < T; i++) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'M') {
      int fx = find(x), fy = find(y);
      pa[fx] = fy;
      dis[fx] += sz[fy];
      sz[fy] += sz[fx];
      sz[fx] = sz[fy];
    } else {
      if (find(x) == find(y)) {
        cout << abs(dis[x] - dis[y]) - 1 << '\n';
      } else cout << -1 << '\n';
    }
  }
  return 0;
}