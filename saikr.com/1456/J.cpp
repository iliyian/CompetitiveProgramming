#include <bits/stdc++.h>
#include <iterator>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> cnt(300);
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cnt[str[i]]++;
    mx = max(mx, cnt[str[i]]);
  }
  vector<int> a;
  int c = 0, i = 0;
  while (str[i] == str.front()) i++, c++;
  a.push_back(c);
  c = 1;
  for (; i < n - 1; i++) {
    if (str[i + 1] != str[i]) {
      a.push_back(c);
      c = 1;
    } else {
      c++;
    }
  }
  if (c) a.push_back(c);

  while (true) {
    bool f = true;
    if (str.size() == 2) break;
    for (int i = 1; i < str.size(); i++) {
      if (str[i] == str[i - 1]) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
    for (int i = 1; i < str.size(); i++) {
      if (str[i] == str[i + 1]) {
        str.erase(str.begin() + i - 1);
        str.erase(str.begin() + i - 1);
        break;
      }
    }
    reverse(str.begin(), str.end());

    for (int i = 1; i < str.size(); i++) {
      if (str[i] == str[i + 1]) {
        str.erase(str.begin() + i - 1);
        str.erase(str.begin() + i - 1);
        break;
      }
    }
    reverse(str.begin(), str.end());
  }

  for (int i = 1; i < str.size(); i++) {
    if (str[i] != str.front()) {
      cout << (n % 2) << '\n';
      return;
    }
  }
  cout << str.size() << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("J.in", "r", stdin);
  freopen("J.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}