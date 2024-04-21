#include <bits/stdc++.h>
using namespace std;

void solve() {
  int q;
  cin >> q;
  vector<int> vec;
  for (int t = 0; t < q; t++) {
    int op, x;
    cin >> op >> x;
    if (op == 1) vec.push_back(x);
    else cout << vec[vec.size() - x] << '\n';
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