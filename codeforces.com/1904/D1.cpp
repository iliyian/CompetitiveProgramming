// date: 2024-03-05 20:49:19
// tag: 关键在于反向思维找到扩散的条件

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  set<pair<int, int>> s;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (a[j] < a[i] && a[i] <= b[j]) {
        s.insert({j, a[i]});
      } else break;
    }
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < a[i] && a[i] <= b[j]) {
        s.insert({j, a[i]});
      } else break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      if (!s.count({i, b[i]})) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}