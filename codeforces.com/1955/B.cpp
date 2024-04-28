#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, c, d;
  cin >> n >> c >> d;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
  }
  sort(a.begin(), a.end());
  if (a.front() == a[1]) {
    cout << "NO\n";
    return;
  }
  vector<int> b;
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= n - 1; j++) {
      int x = a[0] + i * c + j * d;
      b.push_back(x);
    }
  }
  sort(b.begin(), b.end());
  cout << (a == b ? "YES" : "NO") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}