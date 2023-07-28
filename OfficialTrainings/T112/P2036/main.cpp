#include <bits/stdc++.h>
using namespace std;

int suans[11], kus[11], n, ans = 2e9;

void dfs(int idx, int suan, int ku) {
  if (idx >= n) {
    if ((suan == 0 && ku == 0) || (suan == 1 && ku == 1))
      return;
    ans = min(ans, abs(suan - ku));
    return;
  }
  dfs(idx + 1, suan == 0 ? suans[idx] : suan * suans[idx], ku + kus[idx]);
  dfs(idx + 1, suan, ku);
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> suans[i] >> kus[i];
  }
  dfs(0, 0, 0);
  cout << ans;
  return 0;
}