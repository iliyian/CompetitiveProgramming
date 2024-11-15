// date: 2024-11-13 21:22:23
// tag: 有趣的bfs性质,交互

#include <bits/stdc++.h>
#define int long long
using namespace std;

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
  std::vector<int> p(n);
  p[1] = 0;
  int a = 2;
  while (ask(1, a)) {
    a++;
  }
  p[a] = 1;
  int l = 2;
  for (int i = a + 1; i < n; i++) {
    while (ask(l, i)) {
      l++;
    }
    p[i] = l++;
  }
  std::cout << "! ";
  for (int i = 1; i < n; i++) {
    std::cout << p[i] << ' ';
  }
  std::cout << std::endl;
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