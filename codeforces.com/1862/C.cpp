// date: 2023/12/28 12:23:49
// tag: 特殊情况用map防re

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> cnt;
  int h = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int pre = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] != cnt[i] + pre) {
      cout << "NO\n";
      return;
    }
    pre += cnt[i];
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}