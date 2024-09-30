#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, cur = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (cur == x) cur++;
    cur++;
  }
  cout << cur - 1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}