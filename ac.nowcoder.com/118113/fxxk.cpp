#include <bits/stdc++.h>
#define int long long

struct Tr {
  std::priority_queue<int> l;
  std::priority_queue<int, std::vector<int>, std::greater<>> r;
  int lsum = 0, rsum = 0;
  void add(int x) {
    if (l.empty() || x < l.top()) {
      l.push(x);
      lsum += x;
    } else {
      r.push(x);
      rsum += x;
    }
    if (l.size() > r.size() + 1) {
      int x = l.top(); l.pop();
      r.push(x);
      lsum -= x, rsum += x;
    }
    if (r.size() > l.size()) {
      int x = r.top(); r.pop();
      l.push(x);
      lsum += x, rsum -= x;
    }
  }
  int get() {
    return l.size() * l.top() - lsum + rsum - r.size() * l.top();
  }
};

void solve() {
  int n;
  std::cin >> n;
  Tr tx, ty;
  tx.add(0), ty.add(0);
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    tx.add(x), ty.add(y);
    std::cout << tx.get() << ' ' << ty.get() << '\n';
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