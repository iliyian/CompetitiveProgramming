// floyd有必要性

#include <bits/stdc++.h>
using namespace std;

string strcnt[10];
int g[10][10], cnt[10], pa[10], sz[10];

void mul(const string &a, const string &b, string &c) {
  c.clear();
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
}

int main() {
  freopen("data.in", "r", stdin);
  string n;
  int k;
  cin >> n >> k;
  for (int i = 0; i < 10; i++)
    cnt[i] = 0, g[i][i] = true;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = true;
  }

  for (int k = 0; k < 10; k++)
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
        g[i][j] |= g[i][k] & g[k][j];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      cnt[i] += g[i][j];
  }

  for (int i = 0; i < 10; i++) {
    while (cnt[i]) {
      strcnt[i].push_back(cnt[i] % 10);
      cnt[i] /= 10;
    }
  }

  string ans, temp;
  ans.push_back(1);
  
  for (int i = 0; i < n.size(); i++) {
    int t = n[i] - '0';
    mul(ans, strcnt[t], temp);
    ans = temp;
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << char(ans[i] + '0');
  return 0;
}