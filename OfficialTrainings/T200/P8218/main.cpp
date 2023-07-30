#include <bits/stdc++.h>
using namespace std;

int sums[100005];

int main() {
  int n, m;
  cin >> n;
  memset(sums, 0, sizeof(sums));
  for (int i = 1; i <= n; i++) {
    cin >> sums[i];
    sums[i] += sums[i - 1];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    cout << sums[y] - sums[x - 1] << '\n';
  }
  return 0;
}