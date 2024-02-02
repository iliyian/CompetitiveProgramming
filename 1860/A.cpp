#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str, a, b;
  cin >> str;
  for (int i = 0; i < str.size() * 2; i++) {
    a.push_back("()"[i & 1]);
    b.push_back("()"[i >= str.size()]);
  }
  if (a.find(str) == string::npos) {
    cout << "YES\n" << a << '\n';
  } else if (b.find(str) == string::npos) {
    cout << "YES\n" << b << '\n';
  } else { // seems only "()"
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