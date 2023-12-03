#include <bits/stdc++.h>
#define N 10005
using namespace std;

vector<vector<int>> g;
int t[N], ans[N];

int dfs(int u, int sum) {
  if (ans[u]) return ans[u];
  for (int v : g[u]) {
    ans[u] = max(ans[u], dfs(v, sum));
  }
  ans[u] += t[u];
  return ans[u];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int ori, x;
    cin >> ori >> t[i] >> x;
    while (x) {
      g[x].push_back(ori);
      cin >> x;
    }
  }
  cout << dfs(1, 0);
}