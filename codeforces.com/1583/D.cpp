// date: 2024-04-12 19:49:12
// tag: 交互，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  auto ask = [&](const vector<int> &a) {
    cout << "? ";
    for (auto i : a) {
      cout << i << ' ';
    }
    cout << '\n';
    cout.flush();

    int x;
    cin >> x;
    return x;
  };
  vector<int> a(n, 1);
  vector<int> ans(n);
  bool f = false;
  for (int i = n; i >= 2; i--) {
    a.back() = i;
    int x = ask(a);
    if (x) {
      ans.back() = n - i + 1;
      f = true;
      break;
    }
  }
  if (!f) {
    ans.back() = n;
  }
  fill(a.begin(), a.end(), ans.back());
  for (int i = 1; i <= n; i++) {
    if (i == ans.back()) continue;
    a.back() = i;
    int x = ask(a);
    ans[x - 1] = i;
  }
  cout << "! ";
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout.flush();

  return 0;
}