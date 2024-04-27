#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  string str;
  cin >> str;
  string r = str.substr(3, 4) + str.substr(0, 3);
  for (int i = 0; i < 7; i++) {
    cout << int(r[i]);
  }

  return 0;
}