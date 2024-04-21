#include <bits/stdc++.h>
using namespace std;

map<int, map<int, int>> m;

int hashs(const string &s) {
  return s[0] - 'A' + (s[1] - 'A') * 26;
}

int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string u, v;
    cin >> u >> v;
    int h1 = hashs(u), h2 = hashs(v);
    if (h1 != h2) ans += m[h2][h1];
    m[h1][h2]++;
  }
  cout << ans;
  return 0;
}