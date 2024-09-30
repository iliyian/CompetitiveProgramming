#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  bool f = x == 1;
  for (int i = 1; i < n; i++)
    cin >> x;
  cout << (f ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}