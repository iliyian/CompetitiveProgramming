// date: 2024-03-27 20:46:00
// tag: 暴力，思维
// wa#01: 没有考虑到会加成0，也就是漏看条件了
// wa#02: 排序的关键字没变，上一个bug改一半
// wa#03: 1, 2, n 而不是1, 2, 3
// 
// 顺便这题没爆 1e9 就离谱

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = {x, i};
  }
  sort(a.begin() + 1, a.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
    return x.first < y.first;
  });
  vector<int> ans(n + 1);
  if (n & 1) {
    int x = 1, y = 2, z = n;
    if (a[x].first * a[y].first < 0) swap(x, z);
    ans[a[z].second] = a[x].first + a[y].first;
    ans[a[x].second] = ans[a[y].second] = -a[z].first;
  }
  for (int i = (n & 1) ? 3 : 1; i <= n / 2 * 2; i += 2) {
    ans[a[i].second] = -a[i + 1].first;
    ans[a[i + 1].second] = a[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}