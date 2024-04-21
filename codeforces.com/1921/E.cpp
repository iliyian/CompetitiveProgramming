#include <bits/stdc++.h>
using namespace std;

void solve() {
  int h, w, xa, ya, xb, yb;
  cin >> h >> w >> xa >> ya >> xb >> yb;
  string winner = "";
  bool win = false;
  if ((xb - xa) % 2 == 0) {
    winner = "Bob";
    if (xa >= xb) {
      win = false;
    } else if (ya == yb) {
      win = true;
    } else {
      int t = 0;
      if (ya > yb)
        t = w - yb;
      else
        t = yb - 1;
      // optimal的情况下，只可能在边界吃到
      // 即使结果一样，但过程是optimal的
      // 也就是过程的optimal
      // 因为Alice要尽可能远离Bob
      win = (xb - t * 2) >= xa;
    }
  } else {
    winner = "Alice";
    xa++;
    ya += (ya == yb ? 0 : (ya > yb ? -1 : 1));
    if (xa > xb) {
      win = false;
    } else if (ya == yb) {
      win = true;
    } else {
      int t = 0;
      if (ya < yb)
        t = w - ya;
      else
        t = ya - 1;
      win = (xb - t * 2 >= xa);
    }
  }
  cout << (win ? winner : "Draw") << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}