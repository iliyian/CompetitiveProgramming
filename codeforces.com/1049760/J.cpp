#include <bits/stdc++.h>
#define int long long

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
  int n;
  std::cin >> n;
  if (n % 2 == 0) {
    int cnt = 0, a = 0, b = 0;
    for (int i = 1; i <= n; i += 2) {
      int x = ask(i, i + 1);
      cnt += x;
      if (x) {
        a = i, b = i + 1;
      }
    }
    if (cnt >= 2 || cnt == 0) {
      answer(1);
      return;
    }
    int c = 1, d = 2;
    while (c == a || c == b) c++;
    while (d == a || d == b || d == c) d++;
    int x = ask(a, c), y = ask(b, c);
    if (!x && !y) {
      answer(1);
    } else if (x) {
      int z = ask(a, d);
      if (z) {
        answer(2);
      } else {
        answer(1);
      }
    } else {
      int z = ask(b, d);
      if (z) {
        answer(2);
      } else {
        answer(1);
      }
    }
  } else {
    int cnt = 0, a = 0, b = 0;
    for (int i = 1; i <= n - 1; i += 2) {
      int x = ask(i, i + 1);
      cnt += x;
      if (x) {
        a = i, b = i + 1;
      }
    }
    if (cnt >= 2) {
      answer(1);
    } else if (cnt == 0) {
      int x = ask(n, n - 3), y = ask(n, n - 2), z = ask(n, n - 1);
      if (x && y && z) {
        answer(2);
      } else {
        answer(1);
      }
    } else {
      int c = 1;
      while (c == a || c == b) c++;
      int x = ask(a, n), y = ask(b, n);
      assert(!x || !y);
      if (!x && !y) {
        answer(1);
      } else if (x) {
        int z = ask(a, c);
        if (z) {
          answer(2);
        } else {
          answer(1);
        }
      } else {
        int z = ask(b, c);
        if (z) {
          answer(2);
        } else {
          answer(1);
        }
      }
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}