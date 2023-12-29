#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  vector<int> b;
  b.push_back(a[1]);
  for (int i = 2; i <= n; i++) {
    b.push_back(a[i]);
    if (a[i] < a[i - 1]) b.push_back(a[i]);
  }
  cout << b.size() << '\n';
  for (auto i : b)
    cout << i << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}