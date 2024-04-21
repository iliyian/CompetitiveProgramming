// date: 2023/12/24 15:47:11
// tag: 二分不如直接找最值更优
// 最值最优！！！

#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int l; cin >> l;
    a.push_back({l, 1});
  }
  for (int i = 0; i < n; i++) {
    int r; cin >> r;
    a.push_back({r, -1});
  }
  sort(a.begin(), a.end());
  vector<int> d, st;
  for (auto [x, t] : a) {
    if (t == 1) {
      st.push_back(x);
    } else {
      d.push_back(x - st.back());
      st.pop_back();
    }
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  sort(c.begin(), c.end(), greater<int>());
  sort(d.begin(), d.end());

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += d[i] * c[i];
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}