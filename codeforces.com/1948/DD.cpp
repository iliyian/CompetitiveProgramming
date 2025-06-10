#include <bits/stdc++.h>
#define int long long
using namespace std;

string str;

void solve() {
  cin >> str;
  for (int len = (str.size() + 1) / 2; len >= 1; len--) {
    for (int l = 0; l + len * 2 - 1 < str.size(); l++) {
      int r = l + len;
      bool f = true;
      for (int i = 0; i < len; i++) {
        if (str[l + i] != str[r + i] &&
            str[l + i] != '?' && str[r + i] != '?') {
          f = false;
          break;
        }
      }
      if (f) {
        cout << len * 2 << '\n';
        return;
      }
    }
  }
  cout << 0 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}