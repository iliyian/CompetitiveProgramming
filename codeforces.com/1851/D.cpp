#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> s(n + 1), a(n + 1);
  vector<bool> vis(n + 1);
  for (int i = 1; i < n; i++) {
    cin >> s[i];
    a[i] = s[i] - s[i - 1];
  }
  int t = 0, cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] <= n) {
      vis[a[i]] = true;
    }
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      sum += i;
      cnt++;
    }
  }
  if (cnt > 2) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > n) {
      if (sum == a[i]) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      return;
    }
  }
  cout << "NO\n";
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