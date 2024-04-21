#include <bits/stdc++.h>
using namespace std;

vector<int> s, t;
int n, m, c1, c2;
map<int, map<int, int>> f;

int dp(int k) {
  for (int i = 1; i < s.size(); i++)
    for (int j = 1; j < t.size(); j++) {
      if (s[i] == t[j])
        f[i][j] = f[i - 1][j - 1] + 1;
      else
        f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    }
  return f[n * k - 1][m - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int x;
  cin >> n >> m >> c1 >> c2;
  if (c1 == 0 && c2 == 0) {
    cout << 0 << ' ' << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> x, s.push_back(x);
  for (int i = 0; i < m; i++) cin >> x, t.push_back(x);
  
  int prev = -1, len, times = 1, ansk;
  for (int k = 1;; k++) {
    f.clear();
    len = dp(k);
    if (len == prev) times++;
    else times = 1, ansk = k;

    if (times == 2) {
      cout << (len + 1) * c1 << ' ' << ansk * c2;
      return 0;
    }
    prev = len;
    
    for (int i = 0; i < n; i++) s.push_back(s[i]);
    for (int i = 0; i < m; i++) t.push_back(t[i]);
  }
  return 0;
}