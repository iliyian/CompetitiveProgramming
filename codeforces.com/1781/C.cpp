// date: 2024-06-19 21:41:16
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  vector<int> cnt(27), id(27);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    cnt[str[i] - 'a' + 1]++;
    tot += cnt[str[i] - 'a' + 1] == 1;
  }
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return cnt[x] > cnt[y];
  });
  vector<int> rnk(27);
  for (int i = 1; i <= 26; i++) {
    rnk[id[i]] = i;
  }
  int mn = n;
  string ans;
  for (int i = 1; i <= min(str.size(), 26ull); i++) {
    if (str.size() % i == 0) {
      int cur = 0;
      for (int j = 1; j <= 26; j++) {
        if (j <= i) {
          cur += abs((int)str.size() / i - cnt[id[j]]);
        } else {
          cur += cnt[id[j]];
        }
      }
      cur /= 2;
      if (cur < mn) {
        mn = cur;
        string s = str;
        vector<int> curcnt = cnt;
        for (int j = 0; j < n; j++) {
          if (curcnt[str[j] - 'a' + 1] > n / i || rnk[str[j] - 'a' + 1] > i) {
            for (int k = 1; k <= 26; k++) {
              if (curcnt[id[k]] < n / i) {
                s[j] = id[k] + 'a' - 1;
                curcnt[id[k]]++;
                curcnt[str[j] - 'a' + 1]--;
                break;
              }
            }
          }
        }
        ans = s;
      }
    }
  }
  cout << mn << '\n' << ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}