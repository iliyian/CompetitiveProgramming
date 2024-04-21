#include <bits/stdc++.h>
using namespace std;

int H[10001];

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int l, h, r;
  while (cin >> l >> h >> r) {
    for (int i = l; i < r; i++)
      H[i] = max(H[i], h);
  }
  h = 0;
  for (int i = 1; i <= 10000; i++)
    if (H[i] != h)
      h = H[i], cout << i << ' ' << H[i] << ' ';
  return 0;
}