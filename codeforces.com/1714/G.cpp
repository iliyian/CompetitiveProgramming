// date: 2024-05-10 18:08:41
// tag: 树，二分

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n + 1), B(n + 1), dep(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p >> A[i] >> B[i];
    g[p].push_back(i);
  }
  vector<vector<int>> pa(n + 1, vector<int>(21));
  auto dfs = [&](auto self, int u) -> void {
    for (int i = 1; i <= 20; i++) {
      pa[u][i] = pa[pa[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
      pa[v][0] = u;
      A[v] += A[u];
      B[v] += B[u];
      dep[v] = dep[u] + 1;
      self(self, v);
    }
  };
  dep[1] = 1;
  dfs(dfs, 1);
  auto check = [&](int mid, int u) -> int {
    for (int i = 20; i >= 0; i--) {
      if (mid >> i & 1) {
        u = pa[u][i];
        if (!u) return 0;
      }
    }
    return B[u];
  };
  for (int i = 2; i <= n; i++) {
    int l = 0, r = 1 << 20, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid, i) <= A[i]) r = mid - 1, ans = mid;
      else l = mid + 1;
    }
    cout << dep[i] - ans - 1 << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}