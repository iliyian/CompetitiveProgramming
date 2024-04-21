// date: 2024-04-20 12:10:42
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n + 1), c(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sum += b[i];
  }
  int t = sum / (n * (n + 1) / 2);
  if (sum % (n * (n + 1) / 2) || t < n) {
    cout << "NO\n";
    return;
  }
  for (int i = 2; i <= n; i++) {
    c[i] = b[i - 1] - b[i];
  }
  c[1] = b[n] - b[1];
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = (c[i] + t) / n; // ? why not ==0(modn) ?
    if ((c[i] + t) % n || a[i] < 1 || a[i] > (int)1e9) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}