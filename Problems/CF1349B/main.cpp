// date: 2024-03-26 15:55:04
// tag: 思维，递推

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  bool f = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == k) {
      f = true;
    }
  }
  if (a[1] == k && n == 1) {
    cout << "YES\n";
    return;
  }
  if (!f) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i + 1] >= k) {
      if (a[i] >= k || a[i - 1] >= k) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}