#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> m;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    m[{x, y}] = true;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("4.in", "r", stdin);
  freopen("4.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}