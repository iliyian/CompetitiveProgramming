#include <bits/stdc++.h>
using namespace std;

int up[10005], down[10005], p[10005], l[10005], h[10005];
int f[1005];

struct Node {
  int x, y, t;
  bool operator < (const Node &b) const {
    return t > b.t;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> up[i] >> down[i];
  for (int i = 0; i <= n; i++)
    l[i] = 0, h[i] = 0x3f3f3f3f;
  for (int i = 0; i < k; i++) {
    cin >> p[i];
    cin >> l[p[i]] >> h[p[i]];
  }
  
  priority_queue<Node> q;
  for (int i = 1; i <= m; i++)
    q.push({0, i, 0});
  
  int bestx = -1;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (y >= m) y = m;
    if (y <= l[x] || y >= h[x]) continue;
    if (x == n) {
      cout << 1 << '\n' << t;
      return 0;
    }
    bestx = max(bestx, x);
    for (int i = 1;; i++) {
      int yy = y + up[x] * i;
      q.push({x + 1, yy, t + i});
      if (yy - up[x] > m) break;
    }
    q.push({x + 1, y - down[x], t});
  }

  cout << 0 << '\n';
  int ans = 0;
  for (int i = 0; i < k; i++) {
    if (p[i] < bestx)
      ans++;
  }
  cout << ans;
  return 0;
}