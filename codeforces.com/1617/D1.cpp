// date: 2024-04-19 19:16:01
// tag: 构造，模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  auto ask = [&](int a, int b, int c) {
    cout << format("? {} {} {}\n", a, b, c);
    cout.flush();
  };
  vector<int> res(n + 1, -1);
  vector<int> ans(n + 1, -1);
  int a0 = -1, a1 = -1;
  for (int i = 1; i <= n - 2; i++) {
    ask(i, i + 1, i + 2);
    cin >> res[i];
    if (i > 1 && res[i - 1] != res[i]) {
      if (res[i - 1]) a1 = i - 1, a0 = i + 2;
      else a1 = i + 2, a0 = i - 1;
      ans[a1] = 1, ans[a0] = 0;
      break;
    }
  }
  vector<int> imps;
  for (int i = 1; i <= n; i++) {
    if (ans[i] == -1) {
      ask(a0, a1, i);
      cin >> ans[i];
    }
    if (!ans[i]) {
      imps.push_back(i);
    }
  }
  cout << format("! {} ", imps.size());
  for (auto i : imps) {
    cout << i << ' ';
  }
  cout << '\n';
  cout.flush();
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