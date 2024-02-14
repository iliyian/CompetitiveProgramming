#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str[3];
  if (n <= 28) {
    cout << "aa" << char('a' + n - 3);
  } else if (n <= 53) {
    cout << "a" << char('a' + n - 28) << 'z';
  } else {
    cout << char('a' + n - 53) << "zz";
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}