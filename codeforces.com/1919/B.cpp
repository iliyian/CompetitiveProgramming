#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  str = '0' + str;
  vector<int> s(n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + (str[i] == '+' ? 1 : -1);
  }
  cout << abs(s[n]) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}