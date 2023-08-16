#include <bits/stdc++.h>
using namespace std;

int pa[10001], costs[10001], vs[10001], sets[10001], dp[10001];
int find(int x) {return x == pa[x] ? x : pa[x] = find(pa[x]);}

int main() {
  int n, m, W, setcnt = 0;
  cin >> n >> m >> W;
  for (int i = 1; i <= n; i++) pa[i] = i;
  for (int i = 1; i <= n; i++) {
    cin >> costs[i] >> vs[i];
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    pa[find(x)] = find(y);
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) != i) {
      costs[pa[i]] += costs[i];
      vs[pa[i]] += vs[i];
    } else {
      sets[setcnt++] = i;
    }
  }
  for (int i = 0; i < setcnt; i++) {
    int x = sets[i];
    for (int j = W; j >= costs[x]; j--)
      dp[j] = max(dp[j], dp[j - costs[x]] + vs[x]);   
  }
  cout << dp[W];
  return 0;
}