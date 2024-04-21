// date: 2023/12/30 19:57:42
// tag: 反正就是很暴力，分别考虑两条线段是否相交这两种情况
// 然后 one 代表以某个l开始的且厚度为1的线段的长度
// two 代表厚度为2的一些线段的开始和结尾的l以及其相交长度，可以索引到one

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n + 1);
  vector<vector<int>> l(n + 2), r(n + 2);
  set<int> s;
  for (int i = 1; i <= m; i++) {
    int ll, rr;
    cin >> ll >> rr;
    l[ll].push_back(i);
    r[rr + 1].push_back(i);
  }
  int ans = 0;
  map<int, int> one;
  map<pair<int, int>, int> two;
  for (int i = 1; i <= n; i++) {
    for (auto j : l[i]) s.insert(j);
    for (auto j : r[i]) s.erase(j);
    if (s.empty()) ans++;
    else if (s.size() == 1) one[*s.begin()]++;
    else if (s.size() == 2) two[{*s.begin(), *s.rbegin()}]++;
  }
  int ans1 = 0, ans2 = 0;
  priority_queue<int> q;
  for (auto [i, j] : one) q.push(j);
  for (int i = 0; i < 2; i++)
    if (!q.empty())
      ans1 += q.top(), q.pop();
  for (auto [i, j] : two)
    ans2 = max(ans2, j + one[i.first] + one[i.second]);
  cout << ans + max(ans1, ans2) << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C1.in", "r", stdin);
  freopen("C1.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}