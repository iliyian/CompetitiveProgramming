#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  int l = 0, r = 0, cur = 0;
  for (auto c : str) {
    if ((cur % 2 == 0) == (c == '1')) {
      cur++;
    } else {
      cur--; // 反转
    }
    l = min(l, cur);
    r = max(r, cur);
  }
  cout << r - l << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}