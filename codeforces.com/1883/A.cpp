#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("A.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    int ans = str.size(), prev = '1';
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '0') str[i] = '9' + 1;
      ans += abs(str[i] - prev);
      prev = str[i];
    }
    cout << ans << '\n';
  }
  return 0;
}