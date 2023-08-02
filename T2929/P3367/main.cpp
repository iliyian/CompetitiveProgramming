#include <bits/stdc++.h>
using namespace std;

int pa[10001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 0; i < m; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      pa[find(x)] = find(y);
    } else cout << (find(x) == find(y) ? 'Y' : 'N') << '\n';
  }
  return 0;
}