#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, -1, 1};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int _; cin >> _;
  while (_--) {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    map<pair<int, int>, bool> vis;
    for (int i = 0; i < 4; i++) {
      int x1 = xk + dx[i] * a, y1 = yk + dy[i] * b;
      int x2 = xk + dx[i] * b, y2 = yk + dy[i] * a;
      vis[make_pair(x1, y1)] = vis[make_pair(x2, y2)] = true;
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      int x1 = xq + dx[i] * a, y1 = yq + dy[i] * b;
      int x2 = xq + dx[i] * b, y2 = yq + dy[i] * a;
      if (vis[make_pair(x1, y1)]) ans++;
      if (!(x1 == x2 && y1 == y2) && vis[make_pair(x2, y2)]) ans++;
    }
    cout << ans << '\n';
  }
}