#include <bits/stdc++.h>
using namespace std;

int a[81][81], n, m, dp[81][81];

string solve(int row) {
  string res; res.push_back(0);
  int i = 0, j = m;
  dp[i][j] = max(dp[i-1][j] + a[row][i - 1], dp[i][j + 1] + a[row][j + 1])
}

string pow2(int n) {
  string res; res.push_back(1);
  string twos; twos.push_back(2);
  while (n) {
    if (n & 1) res = mul(res, twos);
    n >>= 1;
    twos = mul(twos, twos);
  }
  return res;
}

string mul(const string &a, const string &b) {
  string c;
  c.resize(a.size() + b.size() + 1);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += a[i] * b[j];
      if (c[i + j] >= 10) {
        c[i + j + 1] += c[i + j] / 10;
        c[i + j] %= 10;
      }
    }
  }
  while (!c.back() && c.size() >= 2) c.pop_back();
  while (c.back() >= 10) {
    c.push_back(c.back() / 10);
    c[c.size() - 2] %= 10;
  }
  return c;
}

void add(string &a, const string &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < b.size() - 1; i++) {
    a[i] += b[i];
    if (a[i] >= 10) {
      a[i + 1] += a[i] / 10;
      a[i] %= 10;
    }
  }
  while (a.back() >= 10) {
    a.push_back(a.back() / 10);
    a[a.size() - 2] %= 10;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  string ans; ans.push_back(0);
  for (int i = 0; i < n; i++) {
    add(ans, solve(i));
  }
  for (int i = ans.size(); i >= 0; i--) {
    cout << char(ans[i] + '0');
  }
  return 0;
}