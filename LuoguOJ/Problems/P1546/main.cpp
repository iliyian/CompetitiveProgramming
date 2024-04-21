#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {return w < b.w;}
};
vector<Edge> edges;

int pa[101];

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    pa[i] = i;
    for (int j = 1; j <= N; j++) {
      int w;
      cin >> w;
      edges.push_back({i, j, w});
    }
  }
  sort(edges.begin(), edges.end());
  int ans = 0, cnt = 0;
  for (auto &ed : edges) {
    int u = ed.u, v = ed.v, w = ed.w;
    if (cnt == N - 1) break;
    if (find(u) != find(v)) {
      ans += w;
      pa[find(u)] = find(v);
      cnt++;
    }
  }
  cout << ans;
  return 0;
}