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
  int l = 2, r = 999, ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ask(1, mid) == mid) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  answer(ans + 1);
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