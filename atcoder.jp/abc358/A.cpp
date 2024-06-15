#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  string s, t;
  cin >> s >> t;
  if (s == "AtCoder" && t == "Land") {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}