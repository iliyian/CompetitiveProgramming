// date: 2024/01/25 13:28:00
// tag: 注意调试时首先确认逻辑错误，如果逻辑不存在错误，则是常量键入错误等。
// 极大子矩阵的枚举障碍

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 30005;

int h[N];

struct Node {
  int x, y;
};

void solve() {
  int n, m, cnt;
  cin >> n >> m >> cnt;
  vector<Node> nodes;
  for (int i = 0; i < cnt; i++) {
    int x, y;
    cin >> x >> y;
    nodes.push_back({x, y});
  }
  nodes.push_back({0, 0});
  nodes.push_back({0, m});
  nodes.push_back({n, 0});
  nodes.push_back({n, m});
  int ans = -1;

  sort(nodes.begin(), nodes.end(), [&](const Node &x, const Node &y) {
    return x.y < y.y;
  });
  for (int i = 0; i < nodes.size(); i++) {
    int up = 0, down = n;
    for (int j = i + 1; j < nodes.size(); j++) {
      ans = max(ans, (down - up) * (nodes[j].y - nodes[i].y));
      // 先计算，后更新限制
      if (nodes[j].x < nodes[i].x)
        up = max(up, nodes[j].x);
      else
        down = min(down, nodes[j].x);
    }
  }

  sort(nodes.begin(), nodes.end(), [&](const Node &x, const Node &y) {
    return x.x < y.x;
  });
  for (int i = 1; i < nodes.size(); i++) {
    ans = max(ans, m * (nodes[i].x - nodes[i - 1].x));
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}