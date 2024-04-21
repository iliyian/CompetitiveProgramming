// date: 2024-03-16 00:49:05
// tag: 区间dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

string str;

void solve() {
  cin >> str;
  vector<vector<int>> f(str.size() + 1, vector<int>(str.size() + 1));
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      f[i][j] = (str[i] - str[j]) * (str[i] - str[j])
        * (str[i] != '?') * (str[j] != '?');
    }
  }
  vector<vector<int>> s(str.size() + 1, vector<int>(str.size() + 1));
  for (int len = 1; len < str.size(); len++) {
    for (int i = 1; i + len - 1 < str.size(); i++) {
      s[len][i] = s[len][i - 1] + f[i][i + len - 1];
    }
  }
  cout << 0 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}