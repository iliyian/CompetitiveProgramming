// 如果乘法只在最后用check处理进位，在数据过大时仍然会溢出，因此需要每次计算都进位

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int BASE = 1000000000;
const int WIDTH = 9;

struct Big:vector<long long> {
  Big(long long num = 0) {
    push_back(num);
    check();
  }
  Big(int n, int x) {
    clear();
    assign(n, x);
  }
  Big& check() {
    if (empty()) return *this;
    while (!back() && size() >= 2) pop_back();
    for (int i = 1; i < size(); i++) {
      (*this)[i] += (*this)[i-1] / BASE;
      (*this)[i-1] %= BASE;
    }
    while (back() >= BASE) {
      push_back(back() / BASE);
      (*this)[size()-2] %= BASE;
    }
    return *this;
  }
  Big& operator = (const string &str) {
    clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++) {
      int end = str.length() - i * WIDTH;
      int start = max(0, end - WIDTH);
      push_back(stoll(str.substr(start, end - start)));
    }
    return (*this);
  }
};

istream& operator >> (istream &is, Big &x) {
  string str;
  is >> str;
  x = str;
  return is;
}

ostream& operator << (ostream &os, const Big &x) {
  os << x.back();
  for (int i = x.size() - 2; i >= 0; i--)
    os << setfill('0') << setw(WIDTH) << x[i];
  return os;
}

Big& operator += (Big &a, const Big &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < a.size(); i++) a[i] += b[i];
  return a.check();
}

Big operator + (Big a, const Big &b) {
  return a += b;
}

Big operator * (const Big &a, const Big &b) {
  Big c;
  c.assign(a.size() + b.size(), 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += a[i] * b[j];
      if (c[i + j] >= BASE) { // 如果不判，导致c[i+j+1]必然加上不等于零的数
        // 我怀疑上面的注释有问题
        c[i + j + 1] += c[i + j] / BASE;
        c[i + j] %= BASE;
      }
    }
  }
  while (!c.back() && c.size() >= 2) c.pop_back();
  return c;
}

Big& operator *= (Big &a, const Big &b) {
  a = a * b;
  return a;
}

bool operator < (const Big &a, const Big &b) {
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] != b[i])
      return a[i] < b[i];
  }
  return false;
}

bool operator >= (const Big &a, const Big &b) {
  return !(a < b);
}

Big& operator -= (Big &a, Big b) {
  if (a < b) swap(a, b);
  for (int i = 0; i < b.size(); a[i] -= b[i], i++) {
    if (a[i] < b[i]) {
      int j = i + 1;
      while (!a[j]) j++;
      while (j > i) {
        a[j]--;
        a[--j] += BASE;
      }
    }
  }
  return a.check();
}

// ans=商,a=>余数
Big divmod(Big &a, const Big &b) {
  Big ans;
  for (int t = a.size() - b.size(); a >= b; t--) {
    Big d;
    d.assign(t + 1, 0); // 这不适用于压位高精度，考虑[1,0]和[2]
    d.front() = 1; // ?
    Big c = b * d;
    while (a >= c) {
      a -= c;
      ans += d;
    }
  }
  return ans;
}

Big operator / (const Big &a, int b) {
  Big c(a.size());
  int down = 0;
  for (int i = a.size(); i >= 0; i--) {
    int t = a[i] + down * BASE;
    c[i] = t / b;
    down = t - c[i] * b;
  }
  while (c.size() >= 2 && !c.back()) c.pop_back();
  return c;
}

void operator /= (Big &a, int x) {
  a = a / x;
}

Big operator / (Big a, const Big &b) {
  return divmod(a, b);
}

Big& operator /= (Big &a, const Big &b) {
  a = a / b;
  return a;
}

Big operator % (Big a, const Big &b) {
  divmod(a, b);
  return a;
}

Big& operator %= (Big &a, const Big &b) {
  divmod(a, b);
  return a;
}

Big pow(Big a, Big b) {
  Big res(1);
  while (b > Big(0)) {
    if (b.front() & 1) res *= a;
    a *= a;
    b /= Big(2);
  }
  return res;
}

int main() {
  Big a, b;
  cin >> a >> b;
  cout << pow(a, b);
  return 0;
}