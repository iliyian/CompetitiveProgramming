// date: 2024-03-16 00:49:05
// tag: 区间dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

string str;
int s[5005][5005];

void solve() {
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      s[i][j] = (str[i] - str[j]) * (str[i] - str[j])
        * (str[i] != '?') * (str[j] != '?');
    }
  }
  for (int len = str.size() / 2; len >= 1; len--) {
    
    for (int l = 0; l + len * 2 - 1 < str.size(); l++) {
      f[l]  
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