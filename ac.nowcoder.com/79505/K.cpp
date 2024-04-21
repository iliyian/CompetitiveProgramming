#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, Qcnt;
  cin >> n >> Qcnt;
  vector<pair<int, int>> q2;
  vector<vector<int>> q1(n + 1);
  for (int _ = 1; _ <= Qcnt; _++) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      q1[x].push_back(_);
    } else {
      q2.push_back({x, _});
    }
  }
  int cur = 0;
  vector<int> vec;
  for (auto [x, id] : q2) {
    if (x == cur) {
      vec.push_back(id);
      cur++;
    }
  }
  auto lo = [&](const vector<int> &v, int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };
  auto up = [&](const vector<int> &v, int x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
  };
  vector<int> val(n + 1);
  for (int x = 1; x <= n; x++) {
    int prv = 0;
    for (int i = 0; i < q1[x].size(); i++) {
      int id = q1[x][i];
      int norm = up(vec, id);
      val[x] = norm + 1;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("K.in", "r", stdin);
  freopen("K.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}