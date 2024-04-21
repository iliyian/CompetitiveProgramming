// tag: 微分法，具体一个个分析

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<set<int>> v(n);
  vector<int> cnt(60), score(n);
  set<int> tot;
  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
      int x; cin >> x;
      cnt[x]++;
      v[i].insert(x);
      tot.insert(x);
    }
  }
  int ans = 0;
  for (int i = 0; i < 60; i++) {
    if (cnt[i]) {
      set<int> cur;
      for (auto &se : v) {
        if (!se.count(i)) {
          for (auto val : se)
            cur.insert(val);
        }
      }
      ans = max(ans, int(cur.size()));
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}