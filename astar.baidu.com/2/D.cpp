#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string str;
  cin >> str;
  vector<int> s(str.size());
  for (int i = 0; i < str.size(); i++) {
    s[i] += (str[i] == '(' ? 1 : -1);
    if (i > 0) s[i] += s[i - 1];
  }
  if (s.back() == 0) {
    cout << 0 << '\n';
    return 0;
  }
  int ans = 0;
  if (s.back() == 2) {
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '(' && s[i] >= 2) {
        ans++;
      }
    }
  } else {
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == ')' && s[i] <= -2) {
        ans++;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}