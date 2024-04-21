// date: 2024/02/06 22:17:57
// tag: tmd 并查集x == pa[x] 打成 x = pa[x] 找了好久
// 最小生成树的构建过程

#include <bits/stdc++.h>
#define mod 998244353
#define int long long
#define N 200005
using namespace std;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w < b.w;
  }
};

int siz[N], pa[N];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int qpow(int a, int b) {
  int ans = 1;
  a %= mod;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans % mod;
}

void solve() {
  int n, s;
  cin >> n >> s;
  vector<Edge> vec;
  iota(pa, pa + 1 + n, 0);
  fill(siz, siz + 1 + n, 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    vec.push_back({u, v, w});
  }
  sort(vec.begin(), vec.end());
  int ans = 1;
  for (auto [u, v, w] : vec) {
    int pu = find(u), pv = find(v);
    pa[pu] = pv;
    ans = ans * qpow(s - w + 1, siz[pu] * siz[pv] - 1) % mod;
    siz[pv] += siz[pu];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}