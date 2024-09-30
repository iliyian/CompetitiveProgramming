#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  if (str == "abc") {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++) {
      swap(str[i], str[j]);
      if (str == "abc") {
        cout << "YES\n";
        return;
      }
      swap(str[i], str[j]);
    }
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}