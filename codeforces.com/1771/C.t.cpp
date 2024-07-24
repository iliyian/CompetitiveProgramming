#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= min(n, 101ll); i++) {
    for (int j = i + 1; j <= min(n, 101ll); j++) {
      if (gcd(a[i], a[j]) >= 2) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.t.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}