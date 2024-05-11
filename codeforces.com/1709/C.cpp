// date: 2024-05-10 13:42:51
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string str;
  cin >> str;
  int s = 0, cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '?') {
      cnt++;
    } else if (str[i] == '(') {
      s++;
    } else {
      s--;
    }
    if (cnt + s == 1) cnt = 0, s = 1;
  }
  cout << (cnt == abs(s) ? "YES" : "NO") << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}