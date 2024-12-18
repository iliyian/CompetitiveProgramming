#include <bits/stdc++.h>
using namespace std;

int w[40], n, l, r, ans = 0;

void dfs(int cur, int sum) {
  if (sum > r) return;
  if (sum >= l) ans++;
  for (int i = cur; i < n; i++) {
    dfs(i + 1, sum + w[i]);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++)
    cin >> w[i];
  dfs(0, 0);
  cout << ans;
  return 0;
}