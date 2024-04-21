#include <bits/stdc++.h>
using namespace std;

struct Node {
  double x, y, r, s, i, sum;
};
queue<Node> q;
vector<Node> v;
bitset<1051> vis;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("data.in", "r", stdin);
  double N, tx, ty, R;
  cin >> N >> tx >> ty;
  for (double i = 1; i <= N; i++) {
    double x, y, r;
    cin >> x >> y >> r;
    v.push_back({x, y, r, 0, i, 0});
    if (x == 0 && y == 0) R = r;
  }
  q.push({0, 0, R, 10000, 0, 10000});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    double x = node.x, y = node.y, r = node.r, s = node.s, i = node.i, sum = node.sum;
    if (x == tx && y == ty) {
      cout << (int)sum;
      return 0;
    }
    if (vis[i]) continue;
    vis[i] = true;
    for (auto &n : v) {
      if (dist(x, y, n.x, n.y) == r + n.r) {
        double speed = - s * 1.0 * r / n.r;
        q.push({n.x, n.y, n.r, speed, n.i, sum + abs(speed)});
      }
    }
  }
  cout << -1;
  return 0;
}