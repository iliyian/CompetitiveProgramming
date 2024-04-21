// P2700
// 几乎所有情况，find只需要调用一次

#include <bits/stdc++.h>
using namespace std;

bitset<100001> enemy;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w < b.w;
  }
};

int pa[100001];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < K; i++) {
    int x;
    cin >> x;
    enemy[x] = true;
  }
  priority_queue<Edge> q;
  long long ans = 0;
  for (int i = 0; i < N - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    q.push({u, v, w});
    ans += w;
  }
  for (int i = 0; i < N; i++)
    pa[i] = i;
  while (!q.empty()) {
    Edge ed = q.top(); q.pop();
    int u = ed.u, v = ed.v, w = ed.w;
    int pu = find(u), pv = find(v);
    if (!enemy[pu] || !enemy[pv]) {
      pa[pu] = pv;
      ans -= w;
      if (enemy[pu] || enemy[pv])
        enemy[pu] = enemy[pv] = true;
    }
  }
  cout << ans;
  return 0;
}