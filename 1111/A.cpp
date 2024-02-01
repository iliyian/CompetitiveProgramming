#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b;
  cin >> a >> b;
  auto get = [&](char &ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ? 'a' : 'b';
  };
  for (auto &ch : a)
    ch = get(ch);
  for (auto &ch : b)
    ch = get(ch);
  cout << (a == b ? "Yes": "No");
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}