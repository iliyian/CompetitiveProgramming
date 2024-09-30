#include <bits/stdc++.h>
#define N 100001
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g;
  g.resize(n + 1);
  vector<int> in(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
    in[u]++, in[v]++;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 1) cnt++;
  }
  cout << (cnt + 1) / 2 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}