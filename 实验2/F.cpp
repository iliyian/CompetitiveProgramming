#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("F.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  string str;
  int cnt = 0, pos = 0, i;
  bool f = false;
  for (i = 1; getline(cin, str) && str != "."; i++) {
    if (str.find("chi1 huo3 guo1") != str.npos) {
      if (!f) pos = i, f = true;
      cnt++;
    }
  }
  cout << i - 1 << '\n';
  if (f)
    cout << pos << ' ' << cnt;
  else
    cout << "-_-#";
  return 0;
}