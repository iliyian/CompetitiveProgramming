#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, m;
  cin >> m >> n;
  vector<int> p(m + 1), c(n + 1);
  vector<vector<int>> a(m + 1);
  cin.get();
  for (int i = 1; i <= m; i++) {
    int pre = 0, pos;
    string str;
    getline(cin, str);
    while ((pos = str.find(' ', pre)) != string::npos) {
      int v = stoi(str.substr(pre, pos - pre));
      if (!p[i]) p[i] = v;
      else a[i].push_back(v);
      pre = pos + 1;
    }
    a[i].push_back(stoi(str.substr(pre, str.size() - pos)));
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  

  return 0;
}