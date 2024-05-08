// date: 2024-05-06 13:11:39
// tag: 字符串

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
  int n;
  string str;
  cin >> n >> str;
  vector<int> p(n);
  vector<int> vis(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int pos = i;
    string cur;
    if (!vis[pos]) {
      while (!vis[pos]) {
        vis[pos] = true;
        cur.push_back(str[pos]);
        pos = p[pos];
      }
      string tmp = cur + cur;
      auto pi = prefix_function(tmp);
      a.push_back(tmp.size() - pi[pi.size() - 1]);
    }
  }
  int ans = 1;
  for (int i = 0; i < a.size(); i++) {
    ans = lcm(ans, a[i]);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}