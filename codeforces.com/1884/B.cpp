// 这题我也不知道是怎么改的，就把TEST4过了？？？

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string str;

signed main() {
  freopen("B.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> str;

    while (str.back() == '0') {
      str.pop_back(), n--;
      cout << 0 << ' ';
    }

    int cnt = n;
    priority_queue<int, vector<int>, greater<int>> q1, q0;
    for (int i = n - 1; i >= 0; i--) {
      if (str[i] == '0') q0.push(n - 1 - i);
      else q1.push(n - 1 - i);
    }
    int ans = 0, u, v;
    while (!q0.empty()) {
      u = q0.top(), v = q1.top();
      q0.pop();
      if (u == 0) {
        cout << 0 << ' ';
        q1.push(v);
      } else {
        ans += u - v;
        cout << ans << ' ';
        q1.pop();
        q1.push(u);
      }
      cnt--;
    }
    while (cnt--) {
      cout << -1 << ' ';
    }

    cout << '\n';
  }
  return 0;
}