#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("I.in", "r", stdin);
  freopen("I.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, char>>>
    m(5, vector<pair<int, char>>(n * 2 + 1, {q, 0}));
  for (int _ = 1; _ <= q; _++) {
    int op, a;
    char b;
    cin >> op >> a;
    if (op <= 4) {
      cin >> b;
      if (op == 4) a += n;
      m[op][a] = {q - _, b};
    } else if (op == 5) {
      int r = a;
      for (int c = 1; c <= n; c++) {
        vector<pair<int, int>> cols;
        cols.push_back(m[1][r]);
        cols.push_back(m[2][c]);
        cols.push_back(m[3][r + c]);
        cols.push_back(m[4][r - c + n]);
        sort(cols.begin(), cols.end());
        char col = cols.front().second;
        cout << (col ? col : 'a');
      }
      cout << '\n';
    }
  }

  return 0;
}