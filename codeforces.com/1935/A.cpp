#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  for (int i = 0; i < str.size() - 1 - i; i++) {
    if (str[str.size() - 1 - i] < str[i]) {
      for (int j = str.size() - 1; j >= 0; j--) {
        cout << str[j];
      }
      cout << str << '\n';
      return;
    } else if (str[str.size() - 1 - i] > str[i]) {
      break;
    }
  }
  cout << str << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}