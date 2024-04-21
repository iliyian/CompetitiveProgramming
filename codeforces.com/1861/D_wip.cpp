#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2), up(n + 2), down(n + 2);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    up[i] = up[i - 1] + (a[i] >= a[i - 1]);
  for (int i = n; i >= 1; i--)
    down[i] = down[i + 1] + (a[i] >= a[i + 1]);
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    ans = min(ans, down[i - 1] + up[i]);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}