// date: 2024-06-21 13:13:04
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

string win = "win";

bool find(const vector<int> &a, int x) {
  for (int i = 0; i < 3; i++) {
    if (a[i] == x) {
      return true;
    }
  }
  return false;
}

void solve() {
  int m;
  cin >> m;
  vector<vector<vector<int>>> g(3, vector<vector<int>>(3));
  vector<tuple<int, char, int, char>> ans;
  for (int i = 1; i <= m; i++) {
    string str;
    cin >> str;
    vector<int> a(3), cnt(3);
    for (int j = 0; j < 3; j++) {
      a[j] = (str[j] == 'w' ? 0 : str[j] == 'i' ? 1 : 2);
      cnt[a[j]]++;
    }
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j != k && cnt[j] >= 2 && cnt[k] == 0) {
          if (!g[k][j].empty()) {
            ans.push_back({i, win[j], g[k][j].back(), win[k]});
            g[k][j].pop_back();
          } else {
            g[j][k].push_back(i);
          }
        }
      }
    }
  }

  while (!g[0][1].empty()) {
    int a = g[0][1].back(), b = g[1][2].back(), c = g[2][0].back();
    g[0][1].pop_back();
    g[1][2].pop_back();
    g[2][0].pop_back();
    ans.push_back({a, win[0], b, win[1]});
    ans.push_back({b, win[0], c, win[2]});
  }

  while (!g[1][0].empty()) {
    int a = g[1][0].back(), b = g[2][1].back(), c = g[0][2].back();
    g[1][0].pop_back();
    g[2][1].pop_back();
    g[0][2].pop_back();
    ans.push_back({a, win[1], b, win[2]});
    ans.push_back({a, win[2], c, win[0]});
  }

  cout << ans.size() << '\n';
  for (auto [x, a, y, b] : ans) {
    cout << format("{} {} {} {}", x, a, y, b) << '\n';
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}