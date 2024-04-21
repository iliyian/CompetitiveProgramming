#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1 << 30;

mt19937 R(random_device{}());

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "w", stdout);
  int T = 20, n = 30;
  cout << T << '\n';
  while (T--) {
    cout << n << '\n';
    for (int i = 0; i < n; i++)
      cout << R() % MAX_V + 1 << '\n';
  }
  return 0;
}