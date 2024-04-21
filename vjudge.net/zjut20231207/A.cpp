#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  string str;
  char ch;
  cin >> str;
  // for (int i = 0; i < n; i++) {
  //   cin >> ch;
  //   if (ch == 'U') {
  //     if (!str.empty()) str.pop_back();
  //   } else str.push_back(ch);
  // }
  deque<bool> vt;
  while (x) vt.push_back(x & 1), x /= 2;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'U' && !str.empty()) vt.pop_front();
    else if (str[i] == 'L') vt.push_front(0);
    else if (str[i] == 'R') vt.push_front(1);
  }
  int ans = 0;
  for (int i = 0; i < vt.size(); i++) {
    ans += (1ll << i) * vt[i];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  // int t; cin >> t;
  int t = 1;
  while (t--) solve();
  return 0;
}