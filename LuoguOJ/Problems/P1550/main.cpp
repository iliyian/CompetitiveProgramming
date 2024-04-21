#include <bits/stdc++.h>
using namespace std;

int w[301], pa[301];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w > b.w;
  }
};
priority_queue<Edge> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    pa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    q.push({i, 0, w[i]});
    q.push({0, i, w[i]});
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      q.push({i, j, x});
    }
  }
  
  int cnt = 1, ans = 0;
  while (!q.empty()) {
    Edge e = q.top(); q.pop();
    int u = e.u, v = e.v, w = e.w;
    int pu = find(u), pv = find(v);
    if (pu != pv) {
      pa[pu] = pv;
      ans += w;
      if (++cnt == n + 1) {
        cout << ans;
        return 0;
      }
    }
  }
}