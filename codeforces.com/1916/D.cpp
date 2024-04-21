#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans(100);

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cout << ans[n][i] << " \n"[i == n - 1];
}

void init() {
  ans[1] = {"1"};
  ans[3] = {"169", "196", "961"};
  string zeros;
  for (int i = 5; i <= 99; i += 2) {
    for (auto v : ans[i - 2])
      ans[i].push_back(v + "00");
    zeros.push_back('0');
    ans[i].push_back("1" + zeros + "6" + zeros + "9");
    ans[i].push_back("9" + zeros + "6" + zeros + "1");
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);
  int _; cin >> _;

  init();

  while (_--) solve();
}