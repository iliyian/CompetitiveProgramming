// date:2023/11/28
// tag: 正难则反

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> dv(100005);

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  vector<int> cnt(a[n] + 1);
  vector<int> num(a[n] + 1);
  for (int i = 1; i <= n; i++)
    for (auto j : dv[a[i]]) {
      cnt[j] += (n - i) * num[j];
      num[j]++;
    }
  for (int i = a[n] / 2; i >= 1; i--)
    for (int j = i * 2; j <= a[n]; j += i)
      cnt[i] -= cnt[j];
  int ans = 0;
  for (int i = 1; i <= a[n]; i++)
    ans += i * cnt[i];
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int t; cin >> t;

  for (int i = 1; i <= 100000; i++)
    for (int j = i; j <= 100000; j += i)
      dv[j].push_back(i);

  while (t--) solve();
  return 0;
}