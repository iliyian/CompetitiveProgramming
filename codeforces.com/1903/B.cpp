#include <bits/stdc++.h>
#define N 1005
using namespace std;

int a[N][N];

void solve() {
  int n;
  cin >> n;
  vector<int> ans;
  ans.assign(n + 1, (1 << 30) - 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (i != j)
        ans[i] &= a[i][j];
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j)
        ans[j] &= a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if ((ans[i] | ans[j]) != a[i][j]) {
        cout << "NO\n";
        return;
      }
  cout << "YES\n";
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}