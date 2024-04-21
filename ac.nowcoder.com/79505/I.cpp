#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> one, zero;
  for (int i = 0; i < n; i++) {
    if (str[i] == '0') {
      zero.push_back(i + 1);
    } else {
      one.push_back(i + 1);
    }
  }
  vector<pair<int, int>> ans;
  int cnt = 0;

  if (one.empty()) {
    for (int i = 1; i < zero.size(); i++) {
      ans.push_back({zero[i], zero[i - 1]});
    }
    ans.push_back({zero.front(), zero.back()});
  } else if (zero.empty()) {
    for (int i = 1; i < one.size(); i++) {
      ans.push_back({one[i], one[i - 1]});
    }
    ans.push_back({one.front(), one.back()});
  } else if (one.size() == 1) {
    for (int i = 0; i < zero.size(); i++) {
      ans.push_back({zero[i], one.front()});
    }
    ans.push_back({zero[0], zero[1]});
  } else if (zero.size() == 1) {
    for (int i = 0; i < one.size(); i++) {
      ans.push_back({one[i], zero.front()});
    }
    ans.push_back({one[0], one[1]});
  } else {
    for (int i = 0; i < one.size(); i++) {
      ans.push_back({one[i], zero.front()});
    }
    for (int i = 1; i < zero.size(); i++) {
      ans.push_back({zero[i], one.front()});
    }
    ans.push_back({one.back(), zero.back()});
  }

  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("I.in", "r", stdin);
  freopen("I.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}