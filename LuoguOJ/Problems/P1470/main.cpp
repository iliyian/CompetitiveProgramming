#include <bits/stdc++.h>
using namespace std;

set<string> s;
bitset<200001> f;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  string str;
  int maxn = -1;
  while (cin >> str && str != ".") {
    s.insert(str);
    maxn = max(maxn, int(str.size()));
  }
  string chunk;
  str = " ";
  while (cin >> chunk) {
    str.append(chunk);
  }
  int ans = 0;
  f[0] = true;
  for (int r = 1; r < str.size(); r++) {
    for (int len = 1; len <= min(maxn, r); len++) {
      string temp = str.substr(r - len + 1, len);
      if (f[r - len] && s.count(temp)) {
        f[r] = true;
        ans = r;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}