#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  auto pf = [](const string &str) {
    int n = str.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
      int j = pi[i - 1];
      while (j > 0 && str[j] != str[i]) j = pi[j - 1];
      if (str[j] == str[i]) j++;
      pi[i] = j;
    }
    return pi;
  };
  vector<string> strs(3);
  for (int i = 0; i < 3; i++) {
    cin >> strs[i];
  }
  vector<int> id(3);
  iota(id.begin(), id.end(), 0);
  int ans = 0x3f3f3f3f;
  do {
    int sum = strs[id[0]].size() + strs[id[1]].size() + strs[id[2]].size();
    for (int i = 1; i < 3; i++) {
      string cur = strs[id[i - 1]] + '#' + strs[id[i]];
      vector<int> pi = pf(cur);
      for (int j = strs[id[i - 1]].size() + 1; j < cur.size(); j++) {
        if (pi[j] == strs[id[i - 1]].size()) {
          sum -= j - 2 * strs[id[i - 1]].size();
          break;
        }
      }
    }
    ans = min(ans, sum);
  } while (next_permutation(id.begin(), id.end()));
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _ = 1;

  while (_--) {
    solve();
  }

  return 0;
}