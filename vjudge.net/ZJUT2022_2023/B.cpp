#include <bits/stdc++.h>
using namespace std;

struct Node {
  int x, y;
} nodes[1001];

bool check(int mid) {
  queue<Node> q;
  q.push({0, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y;
    if (x == )
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int w, h;
  cin >> w >> h;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nodes[i].x >> nodes[i].y;
  }
  double l = 0, r = 0x3f3f3f3f, ans = -1;
  while (l + 0.0000001 <= r) {
    double mid = (l + r) / 2;
    if (check(mid)) l = mid + 0.0000001, ans = mid;
    else r = mid - 0.0000001;
  }
  cout << ans;
  return 0;
}