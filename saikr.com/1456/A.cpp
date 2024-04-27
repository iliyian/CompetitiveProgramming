#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  string one = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w', ' '};
  string two = {'b', 'e', 'h', 'k', 'n', 'q', 'u', 'x'};
  string three = "cfilorvy";

  string str;
  getline(cin, str);
  int ans = 0;
  for (char ch : str) {
    if (one.find(ch) != string::npos) {
      ans++;
    } else if (two.find(ch) != string::npos) {
      ans += 2;
    } else if (three.find(ch) != string::npos) {
      ans += 3;
    } else {
      ans += 4;
    }
  }
  cout << ans << '\n';

  return 0;
}