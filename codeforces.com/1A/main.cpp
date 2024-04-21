#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m >> a;
  cout << 1ll * ((n - 1) / a + 1) * ((m - 1) / a + 1);
  return 0;
}