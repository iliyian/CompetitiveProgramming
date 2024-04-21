// O2 NB

#include <bits/stdc++.h>
using namespace std;

int ans = 0, n, m;

void dfs(int count, int prev, int sum) {
  // if (prev + sum > n) return;
  if (count == m) ans += sum == n;
  else for (int i = prev; i + sum <= n; i++) {
    dfs(count+1, i, sum + i);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++)
    dfs(1, i, i);
  cout << ans;
  return 0;
}