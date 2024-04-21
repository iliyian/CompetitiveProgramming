#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  cout << (a % 2 == b % 2 ? "Bob" : "Alice") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}