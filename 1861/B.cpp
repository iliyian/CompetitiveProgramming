#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  bool f = false;
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] == b[i] && a[i + 1] == b[i + 1] && a[i] == '0' && a[i + 1] == '1') {
      f = true;
      break;
    }
  }
  cout << (f ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}