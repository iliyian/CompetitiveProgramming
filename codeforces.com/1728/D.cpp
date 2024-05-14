// date: 2024-05-13 22:40:09
// tag: 博弈

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string str;
  cin >> str;
  int l = 1, r = str.size();
  str = '#' + str;
  vector<vector<int>> mem(r + 1, vector<int>(r + 1, -1));
  auto check = [&](auto self, int l, int r) -> bool {
    if (l + 1 == r) {
      return str[l] != str[r];
    }
    if (mem[l][r] != -1) {
      return mem[l][r];
    }

    int lch = str[l], rch = str[r];
    bool f1 = (lch == str[l + 1] && !self(self, l + 2, r));
    bool f2 = (rch == str[r - 1] && !self(self, l, r - 2));

    bool f3 = (lch == rch && !self(self, l + 1, r - 1));
    
    return mem[l][r] = !((f1 || f3) && (f2 || f3));
  };
  cout << (check(check, l, r) ? "Alice" : "Draw") << '\n';
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