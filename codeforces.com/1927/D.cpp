#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), d(n + 1);
  vector<int> b;
  for (int i = 1; i <= n; i++)
    cin >> a[i], d[i] = a[i] - a[i - 1];
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      b.push_back(i);
    }
  }
  // b.push_back(n);
  int q;
  cin >> q;
  auto get = [&](const int &x) {
    return upper_bound(b.begin(), b.end(), x) - b.begin() - 1;
  };
  // cout << q;
  for (int t = 0; t < q; t++) {
    int l, r;
    cin >> l >> r;
    // 1 3 4
    // 1 2 4 6
    int x = upper_bound(b.begin(), b.end(), l) - b.begin() - 1,
      y = upper_bound(b.begin(), b.end(), r) - b.begin() - 1;
    if (x == y) {
      cout << "-1 -1\n";
      continue;
    }
    if (a[b[x]] == a[b[y]]) {
      cout << l << ' ' << b[x + 1] << '\n';
    } else {
      cout << l << ' ' << r << '\n';
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}