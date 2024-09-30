// date: 2023/12/23 19:09:29
// tag: 找规律

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string str;
  cin >> str;
  int ans = 0, p = str.find('B'), pre = -1, cnt = 0;
  vector<int> lens;
  while (p != string::npos) {
    lens.push_back(p - pre - 1);
    pre = p;
    p = str.find('B', p + 1);
    cnt++;
  }
  lens.push_back(str.size() - pre - 1);
  // cout << '\n';
  sort(lens.begin(), lens.end(), greater<int>());
  for (int i = 0; i < cnt; i++)
    ans += lens[i];
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}