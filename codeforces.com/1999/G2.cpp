#include <bits/stdc++.h>
#define int long long
// using namespace std;

int ask(int x, int y) {
  std::cout << "? " << x << ' ' << y << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(int x) {
  std::cout << "! " << x << std::endl;
}

void solve() {
  int l = 2, r = 999;
  while (l + 1 < r) {
    int lmid = (l * 2 + r) / 3, rmid = (l + 2 * r) / 3;
    int t = ask(lmid, rmid);
    if (t == (lmid + 1) * (rmid + 1)) {
      r = lmid;
    } else if (t == lmid * rmid) {
      l = rmid + 1;
    } else {
      l = lmid + 1, r = rmid;
    }
  }
  if (ask(1, l) != l) {
    answer(l);
  } else {
    answer(r);
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}