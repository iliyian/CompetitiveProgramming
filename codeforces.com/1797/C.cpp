// date: 2024-06-28 20:17:40
// tag: 交互，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

int ask(int x, int y) {
  int ans;
  cout << "? " << x << ' ' << y << endl;
  cin >> ans;
  return ans;
}

void answer(int x, int y) {
  cout << "! " << x << ' ' << y << endl;
}

void solve() {
  int n, m;
  cin >> n >> m;
  int a = ask(1, 1);
  if (1 + a > m) {
    int b = ask(1 + a, 1);
    answer(1 + a, 1 + b);
  } else if (1 + a > n) {
    int c = ask(1, 1 + a);
    answer(1 + c, 1 + a);
  } else {
    int b = ask(1, 1 + a), c = ask(1 + a, 1);
    if (b == c) {
      answer(1 + a, 1 + a);
    } else if (b < c) {
      answer(1 + b, 1 + a);
    } else {
      answer(1 + a, 1 + c);
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}