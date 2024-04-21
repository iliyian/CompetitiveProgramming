// date: 2024/01/29 13:57:42
// tag: 这tmd相同一份代码，本地和cf的两个版本编译器跑出了三个结果
// 反正就是很离谱

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 2), d(n + 2);
  a[0] = a[n + 1] = 0, d[0] = d[n + 1] = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> d[i];
  set<int> cur, liv;
  for (int i = 0; i <= n + 1; i++) {
    cur.insert(i), liv.insert(i);
  }
  for (int t = 1; t <= n; t++) {
    set<int> del, ncur;
    for (auto i : cur) {
      auto it = liv.find(i);
      if (it == liv.end()) continue;
      auto prv = *prev(it), nxt = *next(it);
      if (a[prv] + a[nxt] > d[i]) {
        del.insert(i), ncur.insert(prv), ncur.insert(nxt);
      }
    }
    cout << del.size() << " \n"[t == n];
    for (auto i : del) liv.erase(i);
    cur = ncur;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}