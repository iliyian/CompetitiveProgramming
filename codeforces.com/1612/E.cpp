// date: 2024-04-17 19:18:30
// tag: 贪心，暴力，数学，模拟

#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> m(n + 1), k(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> m[i] >> k[i];
  }
  vector<int> ans;
  double maxr = 0;
  for (int t = 1; t <= 20; t++) {
    vector<int> cnt(N);
    for (int i = 1; i <= n; i++) {
      cnt[m[i]] += min(t, k[i]);
    }
    vector<pair<int, int>> vec;
    for (int i = 1; i <= 200000; i++) {
      vec.push_back({i, cnt[i]});
    }
    sort(vec.begin(), vec.end(), [&](const pair<int, int> &x, const pair<int, int> &y) {
      if (x.second != y.second) {
        return x.second > y.second;
      }
      return x.first > y.first;
    });
    double cur = 0;
    vector<int> curans;
    for (int i = 0; i < min(t, (int)cnt.size()); i++) {
      cur += double(cnt[vec[i].first]) / t;
      curans.push_back(vec[i].first);
    }
    if (cur > maxr) {
      maxr = cur;
      ans = curans;
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << i << ' ';
  }

  return 0;
}