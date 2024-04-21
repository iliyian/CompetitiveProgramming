#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int cur = 2023;
  bool f = true;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (cur % x) {
      f = false;
    }
    cur /= x;
  }
  if (!f) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < k; i++)
    cout << (i ? 1 : cur) << " \n"[i == k - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}