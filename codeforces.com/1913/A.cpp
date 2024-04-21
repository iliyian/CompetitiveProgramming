#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size() - 1; i++)
    if (str[i + 1] != '0') {
      string a = str.substr(0, i + 1), b = str.substr(i + 1, str.size() - i);
      if (stoi(a) >= stoi(b)) continue;
      cout << a << ' ' << b << '\n';
      return;
    }
  cout << -1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}