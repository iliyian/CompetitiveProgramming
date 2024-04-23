// date: 2024-04-23 11:08:48
// tag: 字符串哈希

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> a;
  bool f = false;
  bitset<30000> h, h3;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    a.push_back(str);
    if (str.size() <= 3 && str.front() == str.back()) {
      f = true;
    }
    if (str.size() == 2) {
      int curh = (str[0] - 'a' + 1) * 26 + str[1] - 'a' + 1 + 2000;
      int revh = (str[1] - 'a' + 1) * 26 + str[0] - 'a' + 1 + 2000;
      if (h[revh] || h[revh + 1000]) {
        f = true;
      }
      h[curh] = true;
    }
    if (str.size() == 3) {
      int curh2 = (str[0] - 'a' + 1) * 26 + str[1] - 'a' + 1 + 3000;
      int curh3 = (str[0] - 'a' + 1) * 676
        + (str[1] - 'a' + 1) * 26 + str[2] - 'a' + 1;

      int revh = (str[2] - 'a' + 1) * 26 + str[1] - 'a' + 1 + 2000;
      int revh3 = (str[2] - 'a' + 1) * 676
        + (str[1] - 'a' + 1) * 26 + str[0] - 'a' + 1; 
      if (h[revh] || h3[revh3]) {
        f = true;
      }
      h[curh2] = true;
      h3[curh3] = true;
    }
  }
  if (f) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}