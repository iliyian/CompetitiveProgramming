// date: 2024/01/29 14:50:06
// tag: 关键在于构造数列的过程，即每次增加一个数
// 要着重研究这一构造中的变更所导致的题目要求的内容的变更
// 即关键在于计数非最长递增子序列的芳芳
// 关键在研究过程

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int x;
  cin >> x;
  int ma = 1, mi = 0;
  vector<int> v;
  while (x >= 4) {
    v.push_back(x % 2);
    x >>= 1;
  }
  vector<int> ans;
  ans.push_back(0);
  if (x == 3) {
    ans.push_back(0);
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    // cout << ma++ << ' ';
    ans.push_back(ma++);
    // if (v[i]) cout << mi << ' '; 
    if (v[i]) ans.push_back(mi);
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i << ' ';
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}