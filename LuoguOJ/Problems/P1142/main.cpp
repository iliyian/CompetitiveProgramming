#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  a.reserve(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int x = a[i].first, y = a[i].second;
    for (int j = i + 1; j < n; j++) {
      int cnt = 2;
      for (int k = j + 1; k < n; k++)
        if ((x - a[j].first) * (y - a[k].second) == (x - a[k].first) * (y - a[j].second))
          cnt++;
      ans = max(ans, cnt);
    }
  }
  cout << ans;
  return 0;
}