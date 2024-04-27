#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("I.in", "r", stdin);
  freopen("I.out", "w", stdout);

  int n;
  cin >> n;

  auto calc = [&](auto self, int x) -> string {
    if (x == 0) return string("0");
    if (x == 2) return string("2");
    string ans;
    for (int i = 20; i >= 0; i--) {
      if (x >> i & 1) {
        if (!ans.empty()) ans.push_back('+');
        if (i == 1) ans += "2";
        else {
          auto nxt = self(self, i);
          ans += "2(" + nxt + ")";
        }
      }
    }
    return ans;
  };
  cout << calc(calc, n) << '\n';

  return 0;
}