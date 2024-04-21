// date: 2024/01/31 13:34:11
// tag: water

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, q;
  cin >> n >> a >> q;
  string str;
  cin >> str;
  int cur = a, cnt = 0;
  for (int i = 0; i < q; i++) {
    if (cur >= n) {
      cout << "YES\n";
      return;
    }
    cur += str[i] == '+' ? 1 : -1;
    cnt += str[i] == '+';
  }
  if (cur >= n) {
    cout << "YES\n";
  } else if (cnt + a >= n) {
    cout << "MAYBE\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}