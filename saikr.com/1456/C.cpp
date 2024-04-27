#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  string s1, s2;
  cin >> s1 >> s2;
  vector<int> a, b;

  for (int i = s1.size() - 1; i >= 0; i--) {
    a.push_back(s1[i] - '0');
  }
  for (int i = s2.size() - 1; i >= 0; i--) {
    b.push_back(s2[i] - '0');
  }
  vector<int> c(max(a.size(), b.size()) + 1);
  for (int i = 0; i < c.size(); i++) {
    if (i < a.size()) c[i] += a[i];
    if (i < b.size()) c[i] += b[i];
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }
  while (!c.back() && c.size() >= 2) c.pop_back();
  for (int i = c.size() - 1; i >= 0; i--) {
    cout << char(c[i] + '0');
  }

  return 0;
}