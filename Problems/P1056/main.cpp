#include <bits/stdc++.h>
using namespace std;

array<int, 1000> row, col;

int main() {
  freopen("data.in", "r", stdin);
  int m, n, k, l, d;
  cin >> m >> n >> k >> l >> d;
  for (int i = 0; i < d; i++) {
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    if (x == p) {
      row[min(y, q)]++;
    } else col[min(x, p)]++;
  }
  vector<int> a, b;
  for (int i = 0; i < l; i++) {
    int maxn = -1, maxj;
    for (int j = 0; j < n; j++) {
      if (row[j] > maxn) maxn = row[j], maxj = j;
    }
    b.push_back(maxj);
    row[maxj] = 0;
  }
  for (int i = 0; i < k; i++) {
    int maxn = -1, maxj;
    for (int j = 0; j < m; j++) {
      if (col[j] > maxn) maxn = col[j], maxj = j;
    }
    a.push_back(maxj);
    col[maxj] = 0;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (auto d : a) cout << d << ' ';
  cout << '\n';
  for (auto d : b) cout << d << ' ';
  return 0;
}