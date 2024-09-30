#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int len = n * (n - 1) / 2;
  vector<int> a(len), b(n);
  for (int i = 0; i < len; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < len; i += --n)
    cout << a[i] << ' ';
  cout << int(1e9) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}