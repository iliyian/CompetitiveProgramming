#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a[3];
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[i][j] == '?') {
        sort(a[i].begin(), a[i].end());
        if (a[i] == "?AB") cout << "C";
        if (a[i] == "?AC") cout << "B";
        if (a[i] == "?BC") cout << "A";
        cout << '\n';
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}