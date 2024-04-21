#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  char tru;
  cin >> n >> tru;
  vector<string> a(n * 2);
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i - 1];
  }
  string card = "CDSH";
  // sort(a.begin(), a.end(), [&](const string &x, const string &y) {
  //   return card[x.back] < card[y.front()];
  // });
  // sort(a.begin(), a.end(), [&](const string &x, const string &y) {
  //   if (x.)
  // });  
  auto id = [&](const char &c) -> int {
    if (c == 'C') return 0;
    else if (c == 'D') return 1;
    else if (c == 'S') return 2;
    else if (c == 'H') return 3;
  };
  sort(a.begin(), a.end(), [&](const string &x, const string &y) {
    if (x.back() == y.back()) {
      return x.front() < y.front();
    } else if (x.back() == tru || y.back() == tru) {
      return y.back() == tru;
    } else {
      // 这里写成 card[xy.front()]tmd wa了5发
      // tmd 太紧张了
      return id(x.back()) < id(y.back());
    }
  });
  vector<string> ans;
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i] == a[i + 1]) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  for (int i = 0; i < a.size(); i += 2) {
    if (a[i].back() != a[i + 1].back()) {
      if (a.back().back() != tru) {
        cout << "IMPOSSIBLE\n";
        return;
      }
      ans.push_back(a[i] + ' ' + a.back());
      a.pop_back();
      i--;
    } else {
      if (a[i].front() == a[i + 1].front()) {
        cout << "IMPOSSIBLE\n";
        return;
      }
      ans.push_back(a[i] + ' ' + a[i + 1]);
    }
  }
  for (auto s : ans) {
    cout << s << '\n';
  }
  // cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}