#include <bits/stdc++.h>
using namespace std;

bitset<20001> rows, cols;
bitset<30001> d45, d135;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    rows[x] = cols[y] = true;
    // m = 3, n = 2, x = 2, y = 1, idx = 2
    // x = 1, y = 0, idx = 2
    // x = 2, y = 0, idx = 1
    // x = 0, y = 0, idx = 3
    // x = 0, y = 1, idx = 4
    // x = 3, y = 0, idx = 0
    d45[max(m, n) + y - x] = true;
    d135[x + y] = true;
  }
  
}