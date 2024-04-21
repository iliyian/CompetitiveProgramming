#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] & 1) cnt++;
  }
  cout << (cnt & 1 ? "NO" : "YES") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}