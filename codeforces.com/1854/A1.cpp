#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s(n + 1);
  int idx = 0;
  bool f = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    if (a[i] > 0)
      f = false;
    if (a[i] > a[idx])
      idx = i;
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  if (f) {
    cout << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++)
      cout << n - i - 1 << ' ' << n - i << '\n';
  } else {
    int ans = 5;
    int x = a[idx] * 32;
    vector<pair<int, int>> ops;
    cout << 5 + 2 * (n - 1) << '\n';
    for (int i = 0; i < 5; i++)
      cout << idx << ' ' << idx << '\n';
    for (int i = 0; i < 2; i++)
      cout << 2 << ' ' << idx << '\n';
    for (int i = 3; i <= n; i++)
      for (int j = 0; j < 2; j++)
        cout << i << ' ' << i - 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}