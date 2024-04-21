#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sgn = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) sgn *= -1;
    else if (a[i] == 0) sgn = 0;
  }
  if (sgn <= 0) {
    cout << "0\n";
  } else {
    cout << "1\n1 0\n";
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}