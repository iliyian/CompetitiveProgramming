#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n;
  vector<int> a(n), ans(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> k;
  for (int i = 0; i < n - 1; i++)
    a[i] = min(a[i], a[i + 1]);
  for (int i = 0; i < n; i++) {
    
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}