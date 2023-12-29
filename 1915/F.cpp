#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
    v.push_back(x), v.push_back(y);
  }
  sort(v.begin(), v.end());
  int len = unique(v.begin(), v.end()) - v.begin();
  auto get = [&](const int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i].first > a[j].first && a[i].second < a[j].second
        ||
        a[i].first < a[j].first && a[i].second > a[j].second) {
        ans++;
      }
  cout << ans << '\n';

  // vector<int> id(n);
  // iota(id.begin(), id.end(), 0);
  // sort(id.begin(), id.end(), [&](const int &x, const int &y) {
  //   return get(a[x].first) < get(a[y].first);
  // });
  // // for (int i = 0; i < n; i++)
  // //   cout << a[id[i]].second << " \n"[i == n - 1];
  // set<int> s;
  // int ans = 0;
  // for (int i = 0; i < n; i++) {
  //   int idx = get(a[id[i]].second);
  //   s.insert(idx);
  //   auto ord = s.lower_bound(idx);
  //   s.be
  // }
  // cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}