#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve() {
  string str;
  cin >> str;
  int mx = 0;
  for (int i = 0; i < str.size(); i += 2) {
    string cur = str.substr(i, 2);
    mx = max(mx, stoi(cur));
  }
  cout << mx << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}