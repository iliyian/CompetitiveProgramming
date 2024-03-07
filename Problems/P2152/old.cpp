// tmd压位高精度除法实在是写不来了，
// oi-wiki利用double试商那个现在没看懂

#include <bits/stdc++.h>
#define WIDTH 4
#define BASE 10000
using namespace std;

struct Big:vector<int> {
  Big() {
    clear();
  }
  Big(int x) {
    clear();
    push_back(x);
  }
  Big(int n, int x) {
    clear();
    assign(n, x);
  }
  Big &check() {
    if (empty()) return *this;
    while (!back() && size() >= 2) pop_back();
    for (int i = 1; i < size(); i++) {
      (*this)[i] += (*this)[i - 1] / BASE;
      (*this)[i - 1] %= BASE;
    }
    while (back() >= BASE) {
      push_back(back() / BASE);
      (*this)[size() - 2] %= BASE;
    }
    return *this;
  }
  bool operator < (const Big &b) {
    if (size() != b.size()) return size() < b.size();
    for (int i = size() - 1; i >= 0; i--)
      if ((*this)[i] != b[i])
        return (*this)[i] < b[i];
    return false;
  }
  bool operator >= (const Big &b) {
    return !((*this) < b);
  }
  bool operator == (const Big &b) {
    return !((*this) < b) && !(b < (*this));
  }
  bool isZero() {
    return size() == 1 && back() == 0;
  }
  int mod2() {
    return front() % 2;
  }
  void div2() {
    Big a = *this;
    for (int i = size() - 1; i >= 0; i--) {
      // 注意mod2 == 0
      if (i && ((*this)[i] & 1)) (*this)[i - 1] += BASE;
      (*this)[i] /= 2;
    }
    while (!back() && size() >= 2) pop_back();
    check();
  }

  Big operator * (Big b) {
    Big c(size() + b.size(), 0);
    for (int i = 0; i < size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        c[i + j] += (*this)[i] * b[j];
        if (c[i + j] >= BASE) {
          c[i + j + 1] += c[i + j] / BASE;
          c[i + j] %= BASE;
        }
      }
    }
    // while (!c.back() && c.size() >= 2) c.pop_back();
    return c.check();
  }

  // a >= b
  Big operator - (const Big &b) {
    Big a = *this;
    for (int i = 0; i < b.size(); a[i] -= b[i], i++) {
      if (a[i] < b[i]) {
        int j = i + 1;
        while (!a[j]) j++;
        while (j >= i) {
          --a[j];
          a[--j] += BASE;
        }
      }
    }
    return a.check();
  }

  // Big operator % (Big &b) {
  //   Big a = *this;
  //   for (int i = a.size() - b.size(); a >= b; i--) {
  //     int len = i;
  //     if (a.back() < b.back()) len--;
  //     while (a >= t) {
  //       a -= t;
  //       // ans += d, ans即商
  //     }
  //   }
  //   return a;
  // }

};

// Big gcd(Big a, Big b) {
//   return b == Big(0) ? a : gcd(b, a % b);
// }

istream& operator >> (istream &is, Big &a) {
  string str;
  cin >> str;
  int len = (str.size() - 1) / WIDTH + 1;
  for (int i = 0; i < len; i++) {
    int end = str.size() - i * WIDTH;
    int begin = max(0, end - WIDTH);
    a.push_back(stoi(str.substr(begin, end - begin)));
  }
  return is;
}

ostream& operator << (ostream &os, const Big &a) {
  os << a.back();
  for (int i = a.size() - 2; i >= 0; i--)
    os << setw(WIDTH) << right << setfill('0') << a[i];
  return os;
}

void solve() {
  Big a, b, ans(1);
  cin >> a >> b;
  if (a < b) swap(a, b);
  int cnt = 0;
  while (true) {
    cnt++;
    // 下面这段，不断用gdb的continue正常运行，直接r就会re，太tmd离谱了
    if (b.isZero()) {
      cout << ans * a << '\n';
      return;
    } else if (!a.mod2() && !b.mod2()) {
      ans = Big(2) * ans;
      a.div2();
      b.div2();
    } else if (a.mod2() && !b.mod2()) {
      b.div2();
    } else if (!a.mod2() && b.mod2()) {
      a.div2();
    } else {
      Big d = a - b;
      a = d;
    }
    if (a < b) swap(a, b);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}