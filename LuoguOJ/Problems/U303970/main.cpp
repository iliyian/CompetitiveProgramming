#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(string str) {
  int num = 0;
  int h = -1, m = -1, s = -1, cnt = 0;
  for (int i = str.size() - 1; i >= 0; i--) {
    if (isalpha(str[i])) {
      if (str[i] == 'H') {
        h = num;
      } else if (str[i] == 'M') {
        m = num;
      } else {
        s = num;
      }
      num = 0;
      cnt = 0;
    } else {
      num += (str[i] - '0') * pow(10, cnt++);
    }
  }
  if (h > 24 || m > 59 || s > 59 || h == -1 || m == -1 || s == -1) {
    cout << "Error\n";
    return;
  }
  if (h == 24) h = 0;
  cout << format("{}:{}:{}", h, m, s) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  string str;
  while (cin >> str) {
    solve(str);
  }
  return 0;
}