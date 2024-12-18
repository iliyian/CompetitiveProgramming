// 减法 mod 要 + mod

#include <bits/stdc++.h>
#define mod 10007
using namespace std;

int w[200001];

vector<vector<int>> g;

bool cmp(const int &a, const int &b) {
  return w[a] > w[b];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  g.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 0; i < g.size(); i++) {
    sort(g[i].begin(), g[i].end(), cmp);
  }
  int maxn = -1, anssum = 0;
  for (int u = 1; u <= n; u++) {
    int sum = 0;
    if (g[u].size() >= 2)
      maxn = max(maxn, w[g[u][0]] * w[g[u][1]]);
    // 但是，一个人就是自己的朋友
    for (int v : g[u]) sum = (sum % mod + w[v]) % mod;
    sum = sum * sum % mod;
    for (int v : g[u])
      sum = (sum + mod - w[v] * w[v] % mod) % mod;
    anssum = (anssum + sum % mod) % mod;
  }
  cout << maxn << ' ' << anssum;
  return 0;
}