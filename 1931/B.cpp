#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int x = sum / n, r = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] > x) {
      if (a[i] - x <= r) {
        r -= a[i] - x;
      } else {
        cout << "NO\n";
        return;
      }
    } else {
      r += x - a[i];
    }
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}