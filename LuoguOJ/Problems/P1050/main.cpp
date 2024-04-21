// date: 2024-04-02 21:16:58
// tag: 高精度，动态规划，扩展欧拉定理

#include <bits/stdc++.h>
#define int long long
using namespace std;

hash<string> hashf;

struct Big:vector<int> {
  Big(int x) {
    clear();
    push_back(x);
  }
  Big (int n, int x) {
    clear();
    assign(n, x);
  }
  Big(const string &x) {
    clear();
    for (int i = x.size() - 1; i >= 0; i--) {
      push_back(x[i] - '0');
    }
  }
  string str() {
    string s;
    for (int i = size() - 1; i >= 0; i--) {
      s.push_back((*this)[i] + '0');
    }
    return s;
  }
  Big mulmod (const Big &b, int k) const {
    Big c(b.size() + size() + 1, 0);
    for (int i = 0; i < size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        c[i + j] += (*this)[i] * b[j];
        c[i + j + 1] += c[i + j] / 10;
        c[i + j] %= 10;
      }
    }
    while (!c.back() && c.size() >= 2) c.pop_back();
    return c.mod(k);
  };
  Big& mod(int k) {
    while (size() > k) pop_back();
    // while (size() < k) push_back(0);
    return *this;
  }
  int mod2() {
    return front() % 2;
  }
  void div2() {
    for (int i = size() - 1; i >= 0; i--) {
      if ((*this)[i] % 2 && i) {
        (*this)[i - 1] += 10;
      }
      (*this)[i] /= 2;
    }
    while (!back() && size() >= 2) pop_back();
  }
  Big powmod(Big n, int k) {
    Big ans(1), a = *this;
    while (n.size() >= 2 || n.back()) {
      if (n.mod2()) ans = ans.mulmod(a, k);
      a = a.mulmod(a, k);
      n.div2();
    }
    return ans;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  string num;
  int k;
  cin >> num >> k;
  Big n(num), ans(1);
  n.mod(k);
  unordered_map<int, int> vis;
  for (int len = 1; len <= k; len++) {
    Big cur(len, 0);
    for (int i = 1; i <= len; i++) {
      cur[i - 1] = n[i - 1];
    }
    Big ini = cur.powmod(ans, len);
    bool f = false;
    vis.clear(); // not necessary
    // int h0 = hashf(cur.str());
    for (int i = 1; i <= 15; i++) {
      int h = hashf(cur.str());
      if (vis[h] && (i - vis[h] > 1 || len != k)) {
        // rho型循环确实不算，main.in第一个组数据就是rho
        // 但上面是什么意思？
        ans = ans.mulmod(i - vis[h], INT_MAX);
        f = true;
        break;
      }
      vis[h] = i;
      cur = cur.mulmod(ini, len);
    }
    if (!f) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << ans.str() << '\n';

  return 0;
}