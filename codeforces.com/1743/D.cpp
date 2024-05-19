// date: 2024-05-19 21:29:37
// tag: 字符串，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  string str;
  cin >> n >> str;
  int s1 = -1, s2 = -1;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '1' && s1 == -1) {
      s1 = i;
    }
    if (str[i] == '0' && s1 != -1) {
      s2 = i;
      break;
    }
  }
  string ans;
  for (int d = 1; d <= s2 - s1; d++) {
    string cur;
    for (int i = s1; i < str.size(); i++) {
      cur.push_back(((str[i] == '1' || i - d >= 0 && str[i - d] == '1') ? '1' : '0'));
    }
    if (ans.empty() || ans < cur) {
      ans = cur;
    }
  }
  if (ans.empty()) {
    cout << 0 << '\n';
    return 0;
  }
  cout << ans << '\n';

  return 0;
}