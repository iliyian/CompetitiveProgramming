#include <bits/stdc++.h>
#define int long long

// constexpr int N = 2e5;
// int que[N];

std::list<int> que;

void solve() {
  int q;
  std::cin >> q;
  // int mid = 0;
  auto mid = que.begin();
  // int l = 0, r = 0;
  for (int i = 1; i <= q; i++) {
    int op, x;
    std::cin >> op;
    if (op == 1) {
      std::cin >> x;
      que.push_front(x);
      // que[(l + N - 1) % N] = x;
      // l = (l + N - 1) % N;
      // if ((r - l + N) % N == 1) {
      if (que.size() == 1) {
        mid = que.begin();
        // mid = l;
      } else if (que.size() % 2 == 0) {
      // } else if ((r - l) % 2 == 0) {
        mid--;
      }
    } else if (op == 2) {
      std::cin >> x;
      que.push_back(x);
      // que[r] = x;
      // r = (r + 1) % N;
      if (que.size() == 1) {
      // if ((r - l + N) % N == 1) {
        mid = que.begin();
        // mid = l;
      } else if (que.size() % 2 == 1) {
      // } else if ((r - l) % 2 == 1) {
        mid++;
      }
    } else {
      std::cout << *mid << '\n';
      mid = que.erase(mid);
      if (!que.empty() && que.size() % 2 == 0) {
        mid--;
      }
    }
    // std::cerr << *mid << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}