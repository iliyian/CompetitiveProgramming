#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  vector<char> r;
  for (int i = 0; i < n; i++) {
    r.push_back(str[i]);
  }
  sort(r.begin(), r.end());
  r.erase(unique(r.begin(), r.end()), r.end());
  auto lo = [&](char x) {
    return lower_bound(r.begin(), r.end(), x) - r.begin();
  };
  for (int i = 0; i < n; i++) {
    cout << char(r[r.size() - 1 - lo(str[i])]);
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}