// date: 2023/12/6
// tag: wisdom

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  deque<pair<int, char>> ups, lows;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'b') {
      if (!lows.empty()) lows.pop_back();
    } else if (str[i] == 'B') {
      if (!ups.empty()) ups.pop_back();
    } else {
      if (islower(str[i])) lows.push_back({i, str[i]});
      else ups.push_back({i, str[i]});
    }
  }
  while (!lows.empty() || !ups.empty()) {
    if (lows.empty()) {
      cout << ups.front().second;
      ups.pop_front();
    } else if (ups.empty()) {
      cout << lows.front().second;
      lows.pop_front();
    } else {
      if (lows.front().first < ups.front().first) cout << lows.front().second, lows.pop_front();
      else cout << ups.front().second, ups.pop_front();
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}