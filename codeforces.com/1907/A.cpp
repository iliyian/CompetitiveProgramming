// date: 2023/12/6
// tag: wisdom

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  for (int i = 1; i <= 8; i++) {
    if (i != str[1] - '0') cout << str.front() << i << '\n';
    if ('a' + i - 1 != str[0]) cout << char('a' + i - 1) << str.back() << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}