#include <bits/stdc++.h>
using namespace std;

bool check(const string &s) {
  for (int i = 1; i < s.size(); i++)
    if (s[i] == s[i - 1])
      return false;
  return true;
}

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  if (check(s)) {
    cout << "YES\n";
    return;
  }
  if (!check(t) || t.front() != t.back()) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1] && s[i] == t.front()) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}