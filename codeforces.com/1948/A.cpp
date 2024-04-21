#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  char cur = 'A';
  for (int i = 0; i < n; i += 2) {
    cout << cur << cur;
    cur = cur + 1;
    if (cur == 'Z' + 1) cur = 'A';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}