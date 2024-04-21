#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  bool f = false;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x == k) f = true;
  }
  cout << (f ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}