#include <bits/stdc++.h>
using namespace std;

struct Node {
  int x, id;
  bool operator < (const Node &b) const {
    return x < b.x;
  }
} nodes[50000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  queue<Node> q;
  map<int, int> m;
  set<int> s, t;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> nodes[i].x >> nodes[i].id;
    s.insert(nodes[i].id);
  }
  sort(nodes, nodes + n);
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    int x = nodes[i].x, id = nodes[i].id;
    if (m[id])
      m[id]++;
    else
      m[id] = 1, cnt++, t.insert(id);
    q.push({x, id});
    while (m[q.front().id] >= 2) --m[q.front().id], q.pop();
    if (t.size() == s.size()) {
      ans = min(ans, x - q.front().x);
    }
  }
  cout << ans;
  return 0;
}