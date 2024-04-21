#include <bits/stdc++.h>
#define N 200005
using namespace std;

int pa[N], k[N];
bitset<N> destroyed;

int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}
void unite(int x, int y) {pa[find(x)] = find(y);}

struct Edge {
  int u, v;
};
vector<Edge> g;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m, K;
  cin >> n >> m;
  iota(pa, pa + n, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g.push_back({x, y});
  }
  cin >> K;
  for (int i = 0; i < K; i++) {
    cin >> k[i];
    destroyed[k[i]] = true;
  }
  int cnt = n - K;
  for (auto &[u, v] : g) {
    if (!destroyed[u] && !destroyed[v] && find(u) != find(v)) {
      pa[find(u)] = find(v);
      cnt--;
    }
  }
  return 0;
}