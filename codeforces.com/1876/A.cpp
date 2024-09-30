// date: 2023/12/22
// tag: implementation

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    return b[x] < b[y];
  });
  int t = n - 1, ans = k;
  for (auto i : id) {
    while (t > 0 && a[i] > 0) {
      t--, a[i]--;
      ans += min(k, b[i]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}