// date: 2024-04-19 20:34:25
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
  vector<int> res(n + 1);
  vector<int> six;
  for (int i = 1; i < n; i += 3) {
    ask(i, i + 1, i + 2); // n/3
    cin >> res[i / 3];
  }
  for (int i = 1; i < n; i += 3) {
    if (i > 1 && res[i / 3] != res[i / 3 - 1]) {
      if (res[i / 3]) {
        for (int j = -3; j < 3; j++) {
          six.push_back(j + i);
        }
      } else {
        for (int j = 0; j < 3; j++) six.push_back(j + i);
        for (int j = -3; j < 0; j++) six.push_back(j + i);
      }
      break;
    }
  }
  
  int a0 = -1, a1 = -1;
  vector<int> ok(n + 1), ans(n + 1, -1), res2(n + 1);
  for (int i = 1; i <= 3; i++) {
    if (i < 3) {
      ask(six[i], six[i + 1], six[i + 2]); // 2
      cin >> res2[six[i]];
    } else {
      res2[six[i]] = 1;
    }
    if (res2[six[i]] != res2[six[i - 1]]) {
      assert(res2[six[i]] == 1);
      a1 = six[i + 2], a0 = six[i - 1];
      ok[(a1 - 1) / 3] = ok[(a0 - 1) / 3] = true;

      for (int j = 0; j < 6; j++) {
        if (six[j] != a0 && six[j] != a1) {
          ask(a0, a1, six[j]); // 4
          cin >> ans[six[j]];
        }
      }

      ans[a1] = 1, ans[a0] = 0;
      break;
    }
  }

  for (int i = 1; i < n; i += 3) { // 2n/3
    if (!ok[i / 3]) {
      int t = res[i / 3];

      ask(i, i + 1, t ? a0 : a1);
      int x;
      cin >> x;
      if (x == t ^ 1) {
        ans[i + 2] = t;
        ask(a0, a1, i);
        cin >> ans[i];
        ans[i + 1] = ans[i] ^ 1;
      } else {
        ask(a0, a1, i + 2);
        cin >> ans[i + 2];
        ans[i] = ans[i + 1] = t;
      }
    }
  }

  vector<int> imps;
  for (int i = 1; i <= n; i++) {
    assert(ans[i] != -1);
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