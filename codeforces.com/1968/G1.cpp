// date: 2024-05-03 12:00:23
// tag: kmp，二分

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> prefix_function(const string &s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

void solve() {
  int n, k;
  cin >> n >> k >> k;
  int l = 1, r = n;
  string str;
  cin >> str;
  auto check = [&](int mid) {
    string cur = str.substr(0, mid) + '#' + str;
    vector<int> pi = prefix_function(cur);
    int cnt = 0, lst = -n;
    for (int i = mid + 1; i < cur.size(); i++) {
      if (pi[i] == mid && i - lst >= mid) {
        cnt++;
        lst = i;
      }
    }
    return cnt >= k;
  };
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G1.in", "r", stdin);
  freopen("G1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}