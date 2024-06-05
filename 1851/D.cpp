#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> s(n + 1), a(n + 1);
  vector<int> vis(n + 1);
  int expectsum = 0;
  for (int i = 1; i <= n - 1; i++) {
    cin >> s[i];
    a[i] = s[i] - s[i - 1];
    if (a[i] <= n) {
      vis[a[i]]++;
    }
  }
  if (n == 2 && a[1] <= 2) {
    cout << "YES\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > n) {
      if (expectsum) {
        cout << "NO\n";
        return;
      }
      expectsum = a[i];
    }
  }
  int sum = 0, notvis = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] > 1) {
      if (expectsum) {
        cout << "NO\n";
        return;
      }
      expectsum = i;
    } else if (!vis[i]) {
      sum += i;
      notvis++;
    }
  }
  if (notvis == 1) {
    cout << "YES\n";
    return;
  }
  cout << (expectsum == sum ? "YES" : "NO") << '\n';
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