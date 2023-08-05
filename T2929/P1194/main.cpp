#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {return w < b.w;}
} edges[300000];

int pa[501];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  freopen("data.in", "r", stdin);
  int A, B, ecnt = 0;
  cin >> A >> B;
  for (int i = 0; i < B; i++) {
    for (int j = 0; j < B; j++) {
      int w;
      cin >> w;
      if (!w || w > A) continue;
      edges[ecnt++] = {i + 1, j + 1, w};
    }
  }
  for (int i = 1; i <= B; i++) pa[i] = i;
  sort(edges, edges + ecnt);

  int ans = 0, cnt = 0;
  for (int i = 0; i < ecnt; i++) {
    if (find(edges[i].u) != find(edges[i].v)) {
      pa[find(edges[i].u)] = find(edges[i].v);
      ans += edges[i].w;
      ++cnt;
    }
  }
  if (cnt == B - 1) cout << ans + A;
  else cout << ans + (B - cnt) * A;
  return 0;
}