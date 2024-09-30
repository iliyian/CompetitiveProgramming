#include <bits/stdc++.h>
using namespace std;

// 1 1 2 2 3 3 4 4
// 1 1 2 2 3 3 

void solve() {
  int n;
  cin >> n;
  cout << (n - 1) / 2 + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}