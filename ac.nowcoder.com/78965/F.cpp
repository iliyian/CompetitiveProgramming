#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  string str;
  cin >> str;
  
  vector<vector<int>> pos(27);
  for (int i = 0; i < str.size(); i++) {
    char c = str[i];
    if (c == 'l' || c == 'e' || c == 't' 
      || c == 'c' || c == 'o' || c == 'd') {
        pos[c - 'a'].push_back(i);
    }
  }
  string t = "leetcode";
  auto dfs = [&](auto self, int cur, int po) {
    if (cur == 8) {
      cout << po + 1 << ' ';
      return;
    }
    vector<int> &v = pos[t[cur] - 'a'];
    int p2 = upper_bound(v.begin(), v.end(), po) - v.begin();
    if (p2 == v.size()) {
      cout << 0 << ' ';
      return;
    }
    self(self, cur + 1, v[p2]);
  };
  for (int i = 0; i < str.size(); i++) {
    dfs(dfs, 0, i - 1);
  }

  return 0;
}