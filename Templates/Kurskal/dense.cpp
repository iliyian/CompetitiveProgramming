// CF1245D
// 点权转化为超级源点

#include <bits/stdc++.h>
#define int long long
using namespace std;

int c[2001], k[2001], pa[2001], n;

struct Node {
  int x, y;
};
vector<Node> nodes;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w > b.w;
  }
};
priority_queue<Edge> q;

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

void kruskal() {
  int cnt = 0, ans = 0;
  vector<pair<int, int>> result;
  vector<int> cv;
  while (!q.empty()) {
    Edge ed = q.top(); q.pop();
    int u = ed.u, v = ed.v, w = ed.w;
    if (find(u) != find(v)) {
      pa[find(u)] = find(v);
      ans += w;
      if (!v) cv.push_back(u);
      else result.push_back({u, v});
      if (++cnt == n) break;
    }
  }

  cout << ans << '\n' << cv.size() << '\n';
  for (int i = 0; i < cv.size(); i++)
    cout << cv[i] << ' ';
  cout << '\n' << result.size() << '\n';
  for (auto &p : result)
    cout << p.first << ' ' << p.second << '\n';
}

int getDis(int x, int y) {
  return abs(nodes[x].x - nodes[y].x) + abs(nodes[x].y - nodes[y].y);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n;
  // 占位符
  nodes.push_back({0, 0});
  pa[0] = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    nodes.push_back({x, y});
    pa[i] = i;
  }
  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 1; i <= n; i++)
    cin >> k[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) {
      q.push({i, j, (k[i] + k[j]) * getDis(i, j)});
    }
  for (int i = 1; i <= n; i++)
    q.push({i, 0, c[i]});

  kruskal();
  return 0;
}