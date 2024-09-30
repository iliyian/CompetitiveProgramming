#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a;
  cin >> a;
  a = '0' + a;
  int p = 0x3f3f3f3f;
  for (int i = a.size() - 1; i >= 1; i--) {
    if (a[i] >= '5') {
      a[i - 1]++;
      p = i;
    }
  }
  if (a[0] != '0') cout << a[0];
  for (int i = 1; i < a.size(); i++) {
    cout << char(i >= p ? '0' : a[i]);
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}