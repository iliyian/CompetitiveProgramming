// date: 2024-05-08 13:17:08
// tag: 构造，贪心，堆优化

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    l[i] = i / (b[i] + 1) + 1,
    r[i] = b[i] ? i / b[i] : n;
  }
  vector<int> id(n + 1);
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return tie(l[x], r[x]) < tie(l[y], r[y]);
  });

  vector<int> ans(n + 1);
  priority_queue<pair<int, int>> q;
  int cur = 1;
  for (int i = 1; i <= n; i++) {
    while (cur <= n && l[id[cur]] == i) {
      q.push({-r[id[cur]], cur});
      cur++;
    }
    ans[id[q.top().second]] = i;
    q.pop();
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
    assert(l[i] <= ans[i] && ans[i] <= r[i]);
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