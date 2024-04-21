#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, d;
  cin >> a >> b >> d;
  int cur = a;
  while (true) {
    cout << cur << ' ';
    cur += d;
    if (cur > b) break;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}