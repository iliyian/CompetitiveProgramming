#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {return w > b.w;}
};
vector<Edge> e;

int a[100001], pa[100001];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

bitset<100001> is_enemy;

int main() {
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int enemy;
    cin >> enemy;
    is_enemy[enemy] = true;
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e.push_back({u, v, w});
    ans += w;
  }
  for (int i = 0; i <= n; i++) pa[i] = i;
  sort(e.begin(), e.end());
  for (auto &ed : e) {
    if (is_enemy[ed.u] && is_enemy[ed.v]) continue;
    int pu = find(ed.u), pv = find(ed.v);
    pa[pu] = pv;
    ans -= ed.w;
    if (is_enemy[pu] || is_enemy[pv])
      is_enemy[pu] = is_enemy[pv] = true;
  }
  cout << ans;
  return 0;
}