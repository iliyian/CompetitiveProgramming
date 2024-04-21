#include <bits/stdc++.h>
using namespace std;

mt19937 rd(random_device{}());

void solve() {
  cout << rd() % int(1e9) << ' ' << rd() % int(1e9) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("data.in", "r", stdin);
  freopen("C.in", "w", stdout);
  int _ = 1000;
  cout << _ << '\n';
  while (_--) solve();
}