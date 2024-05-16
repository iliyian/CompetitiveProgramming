// date: 2024-05-15 22:09:43
// tag: 猜

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto ask = [](int x, int y) {
    cout << format("? {} {}", x, y) << endl;
    int ans;
    cin >> ans;
    return ans;
  };

  for (int i = 3;; i++) {
    int x = ask(1, i), y = ask(i, 1);
    if (x == -1 || y == -1) {
      cout << "! " << i - 1 << endl;
      break;
    }
    if (x != y) {
      cout << "! " << x + y << endl;
      break;
    }
  }

  return 0;
}