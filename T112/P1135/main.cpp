// 标准深搜加记忆化

#include <bits/stdc++.h>
using namespace std;

int floors[201], n, a, b;

struct Floor {
  int f, s;
};

queue<Floor> q;
bitset<201> vis;

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) cin >> floors[i];

  q.push(Floor{a, 0});
  while (!q.empty()) {
    Floor u = q.front(); q.pop();
    if (vis[u.f]) continue;
    vis[u.f] = true;
    if (u.f == b) {
      cout << u.s;
      return 0;
    }
    if (u.f + floors[u.f] <= n) q.push(Floor{u.f + floors[u.f], u.s + 1});
    if (u.f - floors[u.f] > 0) q.push(Floor{u.f - floors[u.f], u.s + 1});
  }
  cout << -1;
  return 0;
}