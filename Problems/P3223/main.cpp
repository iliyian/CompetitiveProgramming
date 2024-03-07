// date: 2024-03-06 21:50:05
// tag: 排列组合计算
// wa#01, #02, long long overflow

#include <bits/stdc++.h>
#define BASE 10000
#define WIDTH 4
using namespace std;

struct Big:vector<int> {
  Big(int x) {
    clear();
    push_back(x);
  }
  Big(int n, int x) {
    clear();
    assign(n, x);
  }
  void operator = (const string &str) {
    int len = (str.size() - 1) / WIDTH + 1;
    clear();
    for (int i = 0; i < len; i++) {
      int end = str.size() - i * WIDTH;
      int begin = max(0, end - WIDTH);
      push_back(stoi(str.substr(begin, end - begin)));
    }
  }
  Big operator * (const Big &b) {
    Big c(b.size() + size() + 1, 0);
    for (int i = 0; i < size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        c[i + j] += (*this)[i] * b[j];
        c[i + j + 1] += c[i + j] / BASE;
        c[i + j] %= BASE;
      }
    }
    while (c.size() >= 2 && !c.back()) c.pop_back();
    return c;
  }
  Big operator * (int x) {
    return (*this) * Big(x);
  }
  void operator *= (int x) {
    *this = (*this) * x;
  }
  Big operator - (const Big &b) {
    Big c = *this;
    for (int i = 0; i < b.size(); c[i] -= b[i], i++) {
      if (c[i] < b[i]) {
        int j = i + 1;
        while (!c[j]) j++;
        while (j > i) {
          --c[j];
          c[--j] += BASE;
        }
      }
    }
    while (c.size() >= 2 && !c.back()) c.pop_back();
    return c;
  }
  Big operator / (int x) {
    Big c(size(), 0);
    int down = 0;
    for (int i = size() - 1; i >= 0; i--) {
      int t = (*this)[i] + down * BASE;
      c[i] = t / x;
      down = t - c[i] * x;
    }
    while (c.size() >= 2 && !c.back()) c.pop_back();
    return c;
  }
  void operator /= (int x) {
    *this = (*this) / x;
  }
};

istream& operator >> (istream &is, Big &b) {
  string str;
  is >> str;
  b = str;
  return is;
}

ostream& operator << (ostream &os, const Big &b) {
  os << b.back();
  for (int i = b.size() - 2; i >= 0; i--) {
    os << setw(WIDTH) << setfill('0') << b[i];
  }
  return os;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  auto A = [](int n, int m) -> Big {
    Big ans(1);
    for (int i = n; i >= n - m + 1; i--) {
      ans *= i;
    }
    return ans;
  };
  
  auto C = [](int n, int m) -> Big {
    Big ans(1);
    for (int i = n; i >= n - m + 1; i--) {
      ans *= i;
    }
    for (int i = 2; i <= m; i++) {
      ans /= i;
    }
    return ans;
  };

  Big ans = A(n + 2, n + 2) * C(n + 3, m) * A(m, m)
    - A(n + 1, n + 1) * C(n + 2, m) * A(m, m) * A(2, 2);
  
  cout << ans << '\n';

  return 0;
}