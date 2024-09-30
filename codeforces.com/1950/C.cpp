#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string str;
  cin >> str;
  string h = str.substr(0, 2), m = str.substr(3, 2);
  if (h == "00" || h == "12") {
    cout << "12:";
  } else if (h <= "11") {
    cout << h << ":";
  } else {
    cout << setw(2) << setfill('0') << (stoi(h) - 12) << ':';
  }
  cout << m << ' ';
  cout << (h <= "11" ? "AM" : "PM") << '\n'; 
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