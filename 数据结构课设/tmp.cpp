#include <cstdio>
#include <cstdlib>

#define MAXSIZE (1 << 21)

class complex {
private:
  double x;
  double y;

public:
  complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  complex operator+(const complex &other) const {
    return complex(x + other.x, y + other.y);
  }

  complex operator-(const complex &other) const {
    return complex(x - other.x, y - other.y);
  }

  complex operator*(const complex &other) const {
    return complex(x * other.x - y * other.y, x * other.y + y * other.x);
  }

  constexpr double real() { return x; }
  constexpr double imag() { return x; }
} f[MAXSIZE], g[MAXSIZE], sav[MAXSIZE];

int tr[MAXSIZE];

#include <cmath>
const double pi = acos(-1);


#include <iostream>
#include <stdexcept> // For std::out_of_range

template <typename T> class list {
private:
  struct Node {
    T data;
    Node *next;
    Node *prev;
    Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
  };

public:

  Node *head;
  Node *tail;
  size_t listSize;

  // Constructor
  list() : head(nullptr), tail(nullptr), listSize(0) {}

  // Destructor to free memory
  ~list() { clear(); }

  // Copy constructor
  list(const list &other) : head(nullptr), tail(nullptr), listSize(0) {
    for (const T &item : other) {
      push_back(item);
    }
  }

  // Copy assignment operator
  list &operator=(const list &other) {
    if (this != &other) {
      clear();
      for (const T &item : other) {
        push_back(item);
      }
    }
    return *this;
  }

  // Move constructor
  list(list &&other) noexcept
      : head(other.head), tail(other.tail), listSize(other.listSize) {
    other.head = nullptr;
    other.tail = nullptr;
    other.listSize = 0;
  }

  // Move assignment operator
  list &operator=(list &&other) noexcept {
    if (this != &other) {
      clear();
      head = other.head;
      tail = other.tail;
      listSize = other.listSize;
      other.head = nullptr;
      other.tail = nullptr;
      other.listSize = 0;
    }
    return *this;
  }

  // Returns the number of elements in the list
  size_t size() const { return listSize; }

  bool empty() const { return listSize == 0; }

  // Adds an element to the end of the list
  void push_back(const T &value) {
    Node *newNode = new Node(value);
    if (!tail) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    listSize++;
  }

  // Adds an element to the beginning of the list
  void push_front(const T &value) {
    Node *newNode = new Node(value);
    if (!head) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    listSize++;
  }

  // Removes the last element from the list
  void pop_back() {
    if (!tail) {
      throw std::out_of_range("pop_back on empty list");
    }
    Node *oldTail = tail;
    tail = tail->prev;
    if (tail) {
      tail->next = nullptr;
    } else {
      head = nullptr; // list is now empty
    }
    delete oldTail;
    listSize--;
  }

  // Removes the first element from the list
  void pop_front() {
    if (!head) {
      throw std::out_of_range("pop_front on empty list");
    }
    Node *oldHead = head;
    head = head->next;
    if (head) {
      head->prev = nullptr;
    } else {
      tail = nullptr; // list is now empty
    }
    delete oldHead;
    listSize--;
  }

  // Returns a reference to the last element in the list
  T &back() {
    if (!tail) {
      throw std::out_of_range("back on empty list");
    }
    return tail->data;
  }

  // Returns a const reference to the last element in the list
  const T &back() const {
    if (!tail) {
      throw std::out_of_range("back on empty list");
    }
    return tail->data;
  }

  // Returns a reference to the first element in the list
  T &front() {
    if (!head) {
      throw std::out_of_range("front on empty list");
    }
    return head->data;
  }

  // Returns a const reference to the first element in the list
  const T &front() const {
    if (!head) {
      throw std::out_of_range("front on empty list");
    }
    return head->data;
  }

  // Iterator class
  class Iterator {
  private:
    Node *current;

  public:
    Iterator(Node *node) : current(node) {}

    // Dereference operator
    T &operator*() const {
      if (!current) {
        throw std::out_of_range("Dereferencing a null iterator");
      }
      return current->data;
    }

    // Arrow operator
    T *operator->() const {
      if (!current) {
        throw std::out_of_range("Dereferencing a null iterator");
      }
      return &(current->data);
    }

    // Pre-increment operator
    Iterator &operator++() {
      if (current) {
        current = current->next;
      }
      return *this;
    }

    // Post-increment operator
    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    // Pre-decrement operator
    Iterator &operator--() {
      if (current) {
        current = current->prev;
      }
      return *this;
    }

    // Post-decrement operator
    Iterator operator--(int) {
      Iterator temp = *this;
      --(*this);
      return temp;
    }

    // Equality operator
    bool operator==(const Iterator &other) const {
      return current == other.current;
    }

    // Inequality operator
    bool operator!=(const Iterator &other) const { return !(*this == other); }
  };

  // Returns an iterator pointing to the beginning of the list
  Iterator begin() const { return Iterator(head); }

  // Returns an iterator pointing to one past the end of the list
  Iterator end() const { return Iterator(nullptr); }

  Iterator rbegin() const { return Iterator(tail); }

  void clear() {
    Node *current = head;
    while (current) {
      Node *next = current->next;
      delete current;
      current = next;
    }
    head = tail = nullptr;
    listSize = 0;
  }
};


// #include "list.h"
// #include <list>

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int WIDTH = 4;
constexpr int BASE = 1e4;
// constexpr int WIDTH = 1;
// constexpr int BASE = 10;

class Big {
public:
  Big() { digits.push_back(0); }
  Big(int x) {
    digits.clear();
    if (!x) {
      digits.push_back(0);
    }
    while (x) {
      digits.push_back(x % BASE);
      x /= BASE;
    }
  }
  Big(int modB, int modP) : modB(modB), modP(modP) {}
  Big(int x, int modB, int modP) {
    this->modB = modB;
    this->modP = modP;

    digits.clear();
    if (!x) {
      digits.push_back(0);
    }
    while (x) {
      digits.push_back(x % BASE);
      x /= BASE;
    }
  }
  Big(const char number[], int modB = 10, int modP = 0) {
    this->modB = modB;
    this->modP = modP;

    int tmp = 0, len = 0;
    while (number[len]) {
      len++;
    }
    for (int r = len; r > 0; r -= WIDTH) {
      int l = std::max(r - WIDTH, 0);
      tmp = 0;
      for (int i = l; i < r; i++) {
        tmp = tmp * 10 + number[i] - '0';
      }
      digits.push_back(tmp);
    }
    mod();
  }
  Big(const Big &other) {
    digits = other.digits;
    modB = other.modB;
    modP = other.modP;
  }

  Big &operator=(const Big &other) {
    digits = other.digits;
    modB = other.modB;
    modP = other.modP;
    return *this;
  }

  Big &operator=(const int &x) {
    *this = Big(x, 0, 0);
    return *this;
  }

  Big operator+(const Big &b) const {
    Big c(modB, modP);
    auto i1 = digits.begin(), i2 = b.digits.begin();
    while (i1 != digits.end() && i2 != b.digits.end()) {
      c.digits.push_back(*i1 + *i2);
      i1++, i2++;
    }
    while (i1 != digits.end()) {
      c.digits.push_back(*i1);
      i1++;
    }
    while (i2 != b.digits.end()) {
      c.digits.push_back(*i2);
      i2++;
    }
    c.digits.push_back(0);
    c.carry();
    c.trim();
    c.mod();
    return c;
  };
  Big &operator+=(const Big &b) {
    *this = *this + b;
    return *this;
  }
  Big operator-(const Big &b) const {
    Big a = *this;
    if (a < b) { // (a + mod - b) mod p == (a - b) mod p
      if (!modP) {
        exit(-1);
      }
      while (a.digits.size() < modP) {
        a.digits.push_back(0);
      }
      a.digits.push_back(1);
    }
    auto i1 = a.digits.begin();
    auto i2 = b.digits.begin();
    while (i2 != b.digits.end()) {
      if (*i1 < *i2) {
        auto j = i1;
        j++;
        while (!*j)
          j++;
        while (j != i1) {
          --*j;
          j--;
          *j += BASE;
        }
      }
      *i1 -= *i2;
      i1++, i2++;
    }
    a.trim();
    a.mod();
    return a;
  };
  Big &operator-=(const Big &b) {
    *this = *this - b;
    return *this;
  }
  Big operator*(const Big &b) const {
    int n = digits.size(), m = b.digits.size();
    m += n, n = 1;
    while (n < m)
      n <<= 1;
    for (int i = 0; i < n; i++) {
      f[i] = g[i] = 0;
    }
    int i = 0;
    for (auto it = digits.begin(); it != digits.end(); it++) {
      f[i++] = {double(*it), 0};
    }
    i = 0;
    for (auto it = b.digits.begin(); it != b.digits.end(); it++) {
      g[i++] = {double(*it), 0};
    }
    for (int i = 0; i < n; i++) {
      tr[i] = (tr[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
    }
    fft_recursive(f, n, 1);
    fft_recursive(g, n, 1);
    for (int i = 0; i < n; i++) {
      f[i] = f[i] * g[i];
    }
    fft_recursive(f, n, -1);
    i = 0;
    Big c(modB, modP);
    while (i < m) {
      c.digits.push_back(f[i++].real() / n + 0.5);
    }
    c.carry();
    c.trim();
    c.mod();
    return c;
  };
  Big &operator*=(const Big &b) {
    *this = *this * b;
    return *this;
  };
  Big operator/(const Big &b) const {
    Big x = b, y(1), t;
    // std::list<Big> s1, s2;
    list<Big> s1, s2;

    for (; x <= *this; x += x, y += y)
      s1.push_back(x), s2.push_back(y);

    x = *this;
    Big ans(0);

    for (; !s1.empty(); s1.pop_back(), s2.pop_back())
      if (s1.back() <= x) {
        x -= s1.back();
        ans += s2.back();
      }
    return ans;
  };
  Big &operator/=(const Big &b) {
    *this = *this / b;
    return *this;
  };
  void div2() {
    int carry = 0;
    for (auto it = --digits.end();; --it) {
      int new_digit = *it + carry * BASE;
      *it = new_digit / 2;
      carry = new_digit % 2;
      if (it == digits.begin())
        break;
    }
    trim();
  }
  int mod2() const { return digits.front() % 2; }
  bool iszero() const {
    for (auto &i : digits) {
      if (i) {
        return false;
      }
    }
    return true;
  }
  Big operator^(Big b) const {
    Big ans(1, modB, modP), a(*this);
    ans.mod();
    while (!b.iszero()) {
      if (b.mod2())
        ans = ans * a;
      a = a * a;
      b.div2();
    }
    ans.trim();
    ans.mod();
    return ans;
  };

  bool operator<(const Big &b) const {
    // 我们只需要一个 <
    // 就可以得到其他所有偏序关系，但是由于需要取模，因此大小比较实际上没有意义，仅仅用于避免出现负数
    if (digits.size() != b.digits.size()) {
      return digits.size() < b.digits.size();
    }
    for (auto i1 = digits.rbegin(), i2 = b.digits.rbegin();;) {
      if (*i1 != *i2) {
        return *i1 < *i2;
      }
      if (i1 == digits.begin())
        break;
      i1--, i2--;
    }
    return false;
  }
  bool operator==(const Big &b) const { return !(*this < b) && !(b < *this); }
  bool operator!=(const Big &b) const { return !(*this == b); }
  bool operator>=(const Big &b) const { return !(*this < b); }
  bool operator<=(const Big &b) const { return *this < b || *this == b; }
  bool operator>(const Big &b) const { return !(*this <= b); }

  friend class IO;

private:
  // std::list<i64> digits;
  list<i64> digits;
  int modB, modP;

  void fft_recursive(complex *f, int len, int opt) const {
    if (len == 1)
      return;
    int mid = len / 2;
    for (int i = 0; i < len; i++) {
      sav[i] = f[i];
    }
    complex *fl = f, *fr = f + mid;
    for (int i = 0; i < mid; i++) {
      fl[i] = sav[i << 1], fr[i] = sav[i << 1 | 1];
    }
    fft_recursive(fl, mid, opt);
    fft_recursive(fr, mid, opt);
    complex w(cos(2 * pi / len), sin(2 * pi / len) * opt);
    complex c(1, 0);
    for (int i = 0; i < mid; i++) {
      if (!((i) % 2048))
        c = complex(cos(2 * pi * (i) / len),
                    sin(2 * pi * (i) / len) * opt);
      sav[i] = fl[i] + c * fr[i];
      sav[i + mid] = fl[i] - c * fr[i];
      c = c * w;
    }
    for (int i = 0; i < len; i++) {
      f[i] = sav[i];
    }
  }

  void fft(complex *f, int n, int opt) const {
    if (n == 1)
      return;
    for (int i = 0; i < n; i++) {
      if (i < tr[i]) {
        std::swap(f[i], f[tr[i]]);
      }
    }
    for (int len = 2; len <= n; len <<= 1) {
      complex wn(cos(2 * pi / len), sin(2 * pi / len) * opt);
      int mid = len >> 1;
      for (int l = 0; l < n; l += len) {
        int r = l + mid;
        complex w(1, 0), t;
        for (int i = l; i < r; i++) {
          if (!((i - l) % 1024))
            w = complex(cos(2 * pi * (i - l) / len),
                        sin(2 * pi * (i - l) / len) * opt);
          t = f[i + mid] * w;
          f[i + mid] = f[i] - t;
          f[i] = f[i] + t;
          w = w * wn; // 这里会导致double的精度损失
        }
      }
    }
  }

  void shift(int shift) {
    if (shift >= 0) {
      for (int i = 0; i < shift; i++) {
        digits.push_front(0);
      }
    } else {
      shift = -shift;
      for (int i = 0; i < shift; i++) {
        digits.pop_front();
      }
    }
  }

  void trim() {
    while (digits.size() > 1 && digits.back() == 0) {
      digits.pop_back();
    }
  }

  void mod() {
    while (modP && digits.size() * WIDTH > modP) {
      digits.pop_back();
    }
  }

  void carry() {
    auto i = digits.begin(), j = ++digits.begin();
    while (j != digits.end()) {
      *j += *i / BASE;
      *i %= BASE;
      i++, j++;
    }
  }
};

#define DEBUG 1 // 调试开关
// #define int long long

class IO {
  char buf[MAXSIZE], *p1, *p2;
  char pbuf[MAXSIZE], *pp;

public:
#if DEBUG
#else
  IO() : p1(buf), p2(buf), pp(pbuf) {}

  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
  char gc() {
#if DEBUG // 调试，可显示字符
    return getchar();
#endif
    if (p1 == p2)
      p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }

  bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' || ch == -1;
  }

  constexpr bool isdigit(char ch) const { return ch >= '0' && ch <= '9'; }

  void read(int &x) {
    double tmp = 1;
    bool sign = false;
    x = 0;
    char ch = gc();
    for (; !isdigit(ch); ch = gc())
      if (ch == '-') {
        write("Negative numbers are not allowed!\n");
        exit(-1);
      }
    for (; isdigit(ch); ch = gc())
      x = x * 10 + (ch - '0');
    if (ch == '.') {
      write("Floating point numbers are not allowed!\n");
      exit(-1);
    }
  }

  void read(char *s) {
    char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc())
      *s++ = ch;
    *s = 0;
  }

  void read(char &c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }

  void read(Big &b) {
    char s[MAXSIZE];
    read(s);
    b = Big(s, b.modB, b.modP);
  }

  void push(const char &c) {
#if DEBUG // 调试，可显示字符
    putchar(c);
#else
    if (pp - pbuf == MAXSIZE)
      fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
    *pp++ = c;
#endif
  }

  void write(int x, int width = -1) {
    static int sta[35];
    int top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
      if (width != -1)
        width--;
    } while (x || width != -1 && width);
    while (top)
      push(sta[--top] + '0');
  }

  void write(const char s[]) {
    int i = 0;
    while (s[i]) {
      push(s[i++]);
    }
  }

  void write(const Big &b) {
    auto i = b.digits.rbegin();
    write(*i);
    if (i == b.digits.begin()) return;
    i--;
    while (1) {
      write(*i, WIDTH);
      if (i == b.digits.begin())
        break;
      i--;
    }
  }
};

signed main() {
  IO io;


  Big x, y;
  io.read(x), io.read(y);
  io.write(x * y);
  return 0;

  int t;
  io.read(t);
  while (t--) {
    int b, p;
    char op;
    io.read(b);
    io.read(p);
    if (p % WIDTH != 0) {
      io.write("The power must be a multiple of ");
      io.write(WIDTH);
      io.write(".\n");
    }
    Big x(b, p), y(b, p);
    io.read(x);
    io.read(op);
    io.read(y);
    if (op == '+') {
      io.write(x + y);
    } else if (op == '-') {
      io.write(x - y);
    } else if (op == '*') {
      io.write(x * y);
    } else if (op == '/') {
      io.write(x / y);
    } else if (op == '^') {
      io.write(x ^ y);
    }
    io.push('\n');
  }
  return 0;
}