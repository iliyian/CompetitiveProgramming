// date: 2025-07-24 10:01:06
// tag: hhhhhh是o3-pro和grok4都没有做出来的构造！

#include <bits/stdc++.h>
#define int long long

void print(int x) {
  for (int i = 30; i >= 0; i--) {
    std::cout << (x >> i & 1);
  }
  std::cout << '\n';
}

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::vector<int> ans;
  if (a == 0 && b == 0) {
    if (c == 0) {
      std::cout << 0 << '\n';
      return;
    }
    std::cout << -1 << '\n';
    return;
  }
  auto op = [&](int x) {
    if (x == 1) a = a * 2;
    if (x == 2) b = b / 2;
    if (x == 3) a ^= b;
    if (x == 4) b ^= a;
    ans.push_back(x);
  };
  if (b == 0 || __builtin_clzll(a) < __builtin_clzll(b)) {
    op(4);
  } else if (a == 0 || __builtin_clzll(a) > __builtin_clzll(b)) {
    op(3);
  }
  int p = 30, q = 30;
  while (p >= 0 && a >> p & 1 ^ 1) p--;
  while (q >= 0 && c >> q & 1 ^ 1) q--;
  assert(p != -1);
  if (q == -1) {
    for (int i = p; i >= 0; i--) {
      if (a >> i & 1) {
        op(3);
      }
      op(2);
    }
    assert(a == b && b == c);
  } else if (p < q) {
    for (int i = p + 1; i <= 30; i++) {
      op(1);
      if ((c >> (q - (i - p)) & 1) ^ (a >> p & 1)) {
        op(3);
      }
      if (__builtin_clzll(a) == __builtin_clzll(c)) {
        break;
      }
    }
    for (int i = p - 1; i >= 0; i--) {
      op(2);
      if ((a >> i & 1) ^ (c >> i & 1)) {
        op(3);
      }
    }
    op(2);
    op(4);
    assert(a == c && b == c);
  } else {
    for (int i = p; i >= 0; i--) {
      if ((a >> i & 1) ^ (c >> i & 1)) {
        op(3);
      }
      op(2);
    }
    op(4);
    assert(a == c && b == c);
  }
  assert(ans.size() <= 64);
  std::cout << ans.size() << '\n';
  for (int i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}