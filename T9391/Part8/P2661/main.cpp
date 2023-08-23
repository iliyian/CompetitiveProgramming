#include <bits/stdc++.h>
using namespace std;

int d[200000], pa[200000];

int find(int x) {
  if (x == pa[x]) return x;
  int k = pa[x];
  pa[x] = find(pa[x]);
  d[x] += d[k];
  return pa[x];
}

int main() {
  freopen("data.in", "r", stdin);
  int n, ans = 1 << 30;
  cin >> n;
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 1; i <= n; i++) {
    int x = i, y;
    cin >> y;
    int px = find(x), py = find(y);
    if (px == py) ans = min(ans, d[x] + d[y] + 1);
    else pa[px] = py, d[x] = d[y] + 1;
  }
  cout << ans;
  return 0;
}
