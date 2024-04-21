#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Node {
  int cur, t;
};
queue<Node> q;

bitset<20001> vis;

int main() {
  cin >> n >> m;
  q.push({n, 0});
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int cur = node.cur, t = node.t;
    if (cur == m) {
      cout << t;
      return 0;
    }
    if (vis[cur]) continue;
    vis[cur] = true;
    if (cur <= 0) continue;
    if (cur < m) {
      q.push({cur * 2, t + 1});
    }
    q.push({cur - 1, t + 1});
  }
  return 0;
}