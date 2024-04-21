#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200001], p[200001];

struct Edge {
  int u, v, w;
  bool operator < (const Edge &b) const {
    return w > b.w;
  }
};

struct Node {
  int i, w;
  bool operator < (const Node &b) const {
    return w > b.w;
  }
};

int n, c;
bool cmp(const int &u, const int &v) {
  return u * c - a[u] < v * c - a[v];
}

void solve() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++)
    p[i] = i, cin >> a[i];
  sort(p + 1, p + n + 1, cmp);
  int sum = a[1];
  for (int i = 1; i <= n; i++) {
    if (p[i] == 1) continue;
    if (p[i] * c > sum + a[p[i]]) {
      cout << "NO\n";
      return;
    } else sum += a[p[i]];
  }
  cout << "YES\n";


  // int n, c;
  // cin >> n >> c;
  // for (int i = 1; i <= n; i++) {
  //   cin >> a[i], pa[i] = i;
  // }

  // priority_queue<Edge> g, delay;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j < i; j++)
  //     if (i != j) {
  //       g.push({i, j, i * j * c});
  //       // g.push({j, i, i * j * c});
  //     }
  // }
  // int sum = 0, cnt = 1;
  // while (!g.empty()) {
  //   Edge ed = g.top(); g.pop();
  //   int u = ed.u, v = ed.v, w = ed.w;
  //   int pu = find(u), pv = find(v);
  //   if (pu != pv) {
  //     if (sum + a[u] + a[v] >= w) {
  //       pa[pu] = pv;
  //       sum += a[u] + a[v];
  //       cnt++;
  //     };
  //   }
  // }
  // if (cnt < n) cout << "NO\n";
  // else cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}