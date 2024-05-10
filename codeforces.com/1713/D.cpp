// date: 2024-05-10 12:07:10
// tag: 交互，构造，贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;

  auto ask = [](int x, int y) {
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
  };

  vector<int> cur;
  for (int i = 1; i <= (1 << n); i++) {
    cur.push_back(i);
  }
  while (cur.size() >= 4) {
    vector<int> nxt;
    for (int i = 0; i < cur.size(); i += 4) {
      int a = cur[i], b = cur[i + 1], c = cur[i + 2], d = cur[i + 3];

      int x = ask(a, c);
      if (x == 1) {
        int y = ask(a, d);
        if (y == 1) {
          nxt.push_back(a);
        } else if (y == 2) {
          nxt.push_back(d);
        } else assert(false);
      } else if (x == 2) {
        int y = ask(b, c);
        if (y == 1) {
          nxt.push_back(b);
        } else if (y == 2) {
          nxt.push_back(c);
        } else assert(false);
      } else {
        int y = ask(b, d);
        if (y == 1) {
          nxt.push_back(b);
        } else if (y == 2) {
          nxt.push_back(d);
        } else assert(false);
      }
    }
    cur = nxt;
  }

  auto answer = [](int x) {
    cout << "! " << x << '\n';
    cout.flush();
  };

  if (cur.size() == 1) {
    answer(cur.front());
  } else if (cur.size() == 2) {
    int x = ask(cur.front(), cur.back());
    if (x == 1) {
      answer(cur.front());
    } else {
      answer(cur.back());
    }
  } else assert(false);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}