#include <bits/stdc++.h>
#define int long long

void solve() {
  int q;
  std::cin >> q;
  std::deque<int> q1, q0;
  int d = 1, sum = 0, ans1 = 0, ans0 = 0;
  auto add = [&](int x, std::deque<int> &q1, std::deque<int> &q0, int &ans1, int &ans0) {
    q1.push_back(x);
    ans1 += q1.size() * x;
    sum += x;
    q0.push_front(x);
    ans0 += sum;
  };
  auto shift = [&](std::deque<int> &q1, std::deque<int> &q0, int &ans1, int &ans0) {
    auto y = q1.back();
    ans1 -= q1.size() * y;
    q1.pop_back();
    q1.push_front(y);
    ans1 += sum;

    y = q0.front(); q0.pop_front();
    ans0 -= sum;
    q0.push_back(y);
    ans0 += y * q0.size();
  };
  while (q--) {
    int s, x;
    std::cin >> s;
    if (s == 1) {
      if (d == 1) {
        shift(q1, q0, ans1, ans0);
      } else {
        shift(q0, q1, ans0, ans1);
      }
    } else if (s == 2) {
      d ^= 1;
    } else {
      std::cin >> x;
      if (d == 1) {
        add(x, q1, q0, ans1, ans0);
      } else {
        add(x, q0, q1, ans0, ans1);
      }
    }
    std::cout << (d == 1 ? ans1 : ans0) << '\n';
  }
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