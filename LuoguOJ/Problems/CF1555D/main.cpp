// date: 2024-04-01 17:36:09
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  vector<array<int, 6>> diff(str.size());
  string t[] = {"abc", "acb", "bac", "bca", "cab", "cba"};

  for (int d = 0; d < 6; d++) {
    for (int i = 0; i < str.size(); i++) {
      if (t[d][i % 3] != str[i]) {
        diff[i][d] = 1;
      }
      diff[i][d] += i ? diff[i - 1][d] : 0;
    }
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    array<int, 6> choice = {0, 1, 2, 3, 4, 5};
    int ans = *min_element(choice.begin(), choice.end(), [&](const int &x, const int &y) {
      return diff[r][x] - (l ? diff[l - 1][x] : 0) 
        < diff[r][y] - (l ? diff[l - 1][y] : 0);
    });
    cout << diff[r][ans] - (l ? diff[l - 1][ans] : 0) << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  solve();

  return 0;
}