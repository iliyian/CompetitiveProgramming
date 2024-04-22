// date: 2024-04-22 15:47:07
// tag: 二分，交互

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto ask = [](int x) {
    cout << "+ " << x << '\n';
    cout.flush();
  };

  int l = 1, r = n - 1;
  while (l < r) {
    cerr << l << ' ' << r << '\n';
    int t = l / n + 1;
    int mid = (l + r - 1) / 2 + 1;
    int g = t * n - mid;
    ask(g);

    int x;
    cin >> x;
    if (x == t) {
      r += g;
      l = mid + g;
    } else {
      l += g;
      r = mid - 1 + g;
    }
  }
  cout << "! " << l << '\n';
  cout.flush();

  return 0;
}