// date: 2024/01/31 13:33:48
// tag: 同C,模拟着模拟着就找到规律了

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  // for (int i = 1; i <= n; i++)
  //   cout << id[i] << " \n"[i == n];
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (id[i] < id[i - 1])
      ans++;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}