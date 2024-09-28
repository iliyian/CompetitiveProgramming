#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n), b(n);
  int cntx = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    for (int j = 0; j < m; j++) {
      cnt0 += b[i][j] != a[i][j];
      cnt1 += b[i][j] == a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << (cnt0 < cnt1 ? a[i][j] : (a[i][j] == '.' ? 'X' : '.'));
    }
    std::cout << '\n';
  }
  return 0;
}