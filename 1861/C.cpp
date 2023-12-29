#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  int len = 0, ord = 0, unord = 0;
  bool f = true;
  for (char s : str) {
    switch (s) {
      case '+': len++; break;
      case '-': {
        len--;
        if (len < ord) ord = len;
        if (len < unord) unord = 0;
        break;
      }
      case '1': {
        if (unord > 0) {
          cout << "NO\n";
          return;
        }
        ord = len;
        break;
      }
      case '0': {
        if (len < 2 || len == ord) {
          cout << "NO\n";
          return;
        }
        if (unord == 0) unord = len;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}