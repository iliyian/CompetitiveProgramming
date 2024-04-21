#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  map<char, char> m;
  m['a'] = m['e'] = 'v';
  m['b'] = m['c'] = m['d'] = 'c';
  int len = 0;
  for (int i = 0; i < n - 1; i++) {
    cout << str[i];
    char cur = m[str[i]], nxt = m[str[i + 1]];
    len++;
    if (cur == 'c' && nxt == 'c' && i < n - 2) {
      cout << '.';
      len = 0;
    } else if (cur == 'v' && nxt == 'c' && len >= 2 && i < n - 2
        && m[str[i + 2]] == 'v') {
      cout << '.';
      len = 0;
    }
  }
  cout << str.back() << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}