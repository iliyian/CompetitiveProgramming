#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int WIDTH = 4;
constexpr int BASE = 10000;

struct Hint:vector<int> {
  Hint() {
    push_back(0);
  };
  void check() {
    
  }
  void operator = (const string &str) {
    int len = (str.size() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++) {
      int l = i * WIDTH,
      r = min(str.size(), l + WIDTH - 1);
      push_back(stoll(str.substr(l, r - l)));
    }
    check();
  }
};

istream& operator >> (istream& is, Hint &x) {
  string str;
  is >> str;
  x = str;
  return is;
}

void solve() {
  int n;
  string str;
  cin >> n >> str;
  vector<int> pre(n + 1);
  pre[1] = 9;
  for (int i = 1; i <= n; i++) {
    pre[i] = 10 * pre[i - 1] + i * 9;
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    int x = str[i] - '0';
    ans += x * i * pre[i];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}