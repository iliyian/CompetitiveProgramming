#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  cout << max(n, m) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}