// date: 2024-04-16 17:36:09
// tag: 并查集，暴力

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> x(m + 1), y(m + 1);
  vector<int> pa(n + 1), siz(n + 1);
  fill(siz.begin(), siz.end(), 1);
  iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (siz[x] < siz[y]) swap(x, y);
    pa[y] = x;
    siz[x] += siz[y];
  };
  int rep = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (find(find, x) == find(find, y)) {
      rep++;
    } else merge(x, y);
    vector<int> vec;
    for (int j = 1; j <= n; j++) {
      if (pa[j] == j) {
        vec.push_back(siz[j]);
      }
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int ans = 0;
    for (int j = 0; j <= rep; j++) {
      ans += vec[j];
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}