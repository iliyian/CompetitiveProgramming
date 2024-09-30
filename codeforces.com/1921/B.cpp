#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int cnt = 0;
  int acnt = 0, bcnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cnt++;
      acnt += a[i] == '1', bcnt += b[i] == '1';
    }
  }
  cout << cnt - min(acnt, bcnt) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}