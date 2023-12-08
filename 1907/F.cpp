// date: 2023/12/7
// tag: wisdom, dp

#include <bits/stdc++.h>
#define N 100005
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(2 * n + 1), f(2 * n + 1), g(2 * n + 1);
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], a[i + n] = a[i];
    if (a[i] != a[1]) flag = true;
  }
  for (int i = 1; i <= n * 2; i++) {
    if (a[i] >= a[i - 1]) f[i] = f[i - 1] + 1;
    else f[i] = 1;
    if (a[i] <= a[i - 1]) g[i] = g[i - 1] + 1;
    else g[i] = 1;
  }
  int ans = 0x3f3f3f3f;
  for (int i = n + 1; i <= 2 * n; i++) {
    // shift to left means R + shiftRight + R
    if (f[i] == n) {
      ans = min(ans, min(2 * n - i, i - n + 2));
    }
    if (g[i] == n) {
      ans = min(ans, min(2 * n - i + 1, i - n + 1));
    }
  }
  if (!flag) cout << 0 << '\n';
  else cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}