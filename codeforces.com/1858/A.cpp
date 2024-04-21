// date: 2024/02/07 21:27:02
// tag: optimally 就是一步只走一个吗

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a + c % 2 > b ? "First" : "Second") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}