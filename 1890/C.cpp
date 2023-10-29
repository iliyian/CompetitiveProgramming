#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  if (n & 1) {
    cout << "-1\n";
    return;
  }
  int cnt = 0;
  vector<int> ans;
  for (int i = 0; i < n / 2; i++) {
    if (cnt > 300) {
      cout << "-1\n";
      return;
    }
    if (str[i] == '1' && str[n - i - 1] == '1') {
      cnt++;
      ans.push_back(i);
      str.insert(i, "01");
      n += 2;
    } else if (str[i] == '0' && str[n - i - 1] == '0') {
      cnt++;
      ans.push_back(n - i);
      str.insert(n - i, "01");
      // str.insert(n - 1 - i, '1');
      n += 2;
    }
  }
  cout << cnt << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}