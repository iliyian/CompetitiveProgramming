#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int l = 0, r = n - 1;
  for (int i = 0; i < n; i++)
    if (str[i] == 'B') {
      l = i;
      break;
    }
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == 'B') {
      r = i;
      break;
    }
  }
  cout << r - l + 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}