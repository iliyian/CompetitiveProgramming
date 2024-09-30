// date: 2023/12/16
// tag: 可行性而不是必要性

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if (n & 1 ^ 1) {
    cout << 2 << '\n';
    cout << 1 << ' ' << n << '\n';
    cout << 1 << ' ' << n << '\n';
  } else {
    cout << 4 << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
    cout << n - 1 << ' ' << n << '\n';
    cout << n - 1 << ' ' << n << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}