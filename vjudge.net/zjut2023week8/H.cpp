// date: 2023/12/9
// tag: 离散化
// wa#010203: tmd, b的范围搞错了，应该是m不是n
// wa#04: 优化时候wa，离散化后要注意原长度和len的区别，以及注意v.size()

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("H.in", "r", stdin);
  int n, m;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> v;
  for (int i = 1; i <= n; i++)
    cin >> a[i], v.push_back(a[i]);

  cin >> m;
  vector<int> b(m + 1), c(m + 1);
  for (int i = 1; i <= m; i++) 
    cin >> b[i], v.push_back(b[i]);
  for (int i = 1; i <= m; i++)
    cin >> c[i], v.push_back(c[i]);

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  auto get = [&](int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };

  vector<int> cnt(v.size() + 1);
  for (int i = 1; i <= n; i++)
    cnt[get(a[i])]++;

  vector<pair<int, int>> ans;
  for (int i = 1; i <= m; i++) {
    ans.push_back({cnt[get(b[i])], cnt[get(c[i])]});
  }
  cout << max_element(ans.begin(), ans.end()) - ans.begin() + 1;
}