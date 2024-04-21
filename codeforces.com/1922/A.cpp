#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < n; i++) {
    if (a[i] != c[i] && b[i] != c[i]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}