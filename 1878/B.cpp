#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  a[0] = 1, a[1] = 3;
  cout << 1 << ' ' << 3 << ' ';
  for (int i = 2; i < n; i++)
    cout << i + 3 << " \n"[i == n - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}