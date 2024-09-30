#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, t;
  int u[6], d[6];
  while (cin >> s >> t) {
    for (int i = 0; i < 6; i++)
      u[i] = s[i] - t[i], d[i] = s[i] - t[i] + 10;
    
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}