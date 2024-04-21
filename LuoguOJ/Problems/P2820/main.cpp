#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w > b.w;
  }
};
priority_queue<Edge> q;

int pa[101];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  int n, k, sum = 0;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    q.push({u, v, w});
    // q.push({v, u, w});
    sum += w;
  }
  for (int i = 1; i <= n; i++) pa[i] = i;
  int cnt = 0;
  while (!q.empty()) {
    Edge ed = q.top(); q.pop();
    int x = ed.u, y = ed.v, w = ed.w;
    int px = find(x), py = find(y);
    if (px != py) {
      pa[px] = py;
      cnt++;
      sum -= w;
      if (cnt == n - 1) {
        cout << sum;
        return 0;
      }
    }
  }
  return 0;
}