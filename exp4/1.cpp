#include <bits/stdc++.h>
using namespace std;

void solve() {
  int cnt = 0;
  string col[] = {"red", "blue", "yellow", "black"};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++)
        if (i != j && i != k && j != k) {
          cout << ++cnt << ' ';
          cout << col[i] << ' ' << col[j] << ' ' << col[k] << '\n';
        }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}