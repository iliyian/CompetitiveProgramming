// date: 2024-04-28 16:04:04
// tag: 构造，递推

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> c(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  int cnt = sum / n, d = 0;
  vector<int> ans(n + 1), b(n + 1);
  for (int i = n; i >= 0; i--) {
    d += b[i];
    if (c[i] + d == i) {
      ans[i] = 1;
    }
    d--;
    b[i - cnt]++;
    if (ans[i] == 1) {
      cnt--;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}