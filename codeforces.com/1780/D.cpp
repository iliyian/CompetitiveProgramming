// date: 2024-06-18 17:38:26
// tag: lowbit，位运算，交互

#include <bits/stdc++.h>
using namespace std;

int ask(int x) {
  cout << format("- {}", x) << endl;
  cout.flush();
  int ans;
  cin >> ans;
  return ans;
}

void answer(int x) {
  cout << format("! {}", x) << endl;
}

void solve() {
  int cnt;
  cin >> cnt;
  int ans = 0, low = 0;
  while (cnt) {
    int cur = ask(1 << low);
    ans += 1 << low;
    low = cur - cnt + 1;
    cnt = cur - low;
  }
  ans += (1 << low) - 1;
  answer(ans);
}

signed main() {
  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}