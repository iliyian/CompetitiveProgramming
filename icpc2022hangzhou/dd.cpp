#include <bits/stdc++.h>
#define int long long
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define PII pair<int, int>
#define ull unsigned long long
// #define lson (o << 1)
// #define rson (o << 1 | 1)
#define mt ((l + r) / 2)
#define lowbit(x) x & -x
#define endl '\n'
using namespace std;
using ll = long long;
inline int read() {
  int k = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  } // getchar_unlocked()
  while (c >= '0' && c <= '9')
    k = k * 10 + c - '0', c = getchar();
  return k * f;
}
template <typename T> T qpow(T a, ll n) {
  T ans = 1;
  while (n) {
    if (n & 1)
      ans = ans * a;
    n >>= 1;
    a = a * a;
  }
  return ans;
}
int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, y, x);
  y -= (a / b) * x;
  return d;
}
template <typename T> inline void print(T x) {
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T> inline void Pr(T x, char c = '\n') {
  if (x < 0)
    putchar('-'), x = -x;
  print(x);
  putchar(c);
}
inline void write(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}
const int maxn = 1e6 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;
// const int p = 1e9 + 7;
const int N = 3e5 + 10;
// int a[maxn],b[maxn];
// int a[N],b[N];
// const int N = 2e5 + 10;
// string s[705];
int a[N], b[N];
set<string> s;
void solve() {
  int n;
  cin >> n;
  double sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  double qq = sum * 1.0 / (n + 1);
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      cout << fixed << setprecision(6) << qq * 2 << " ";
    else
      cout << fixed << setprecision(6) << qq << " ";
  }
  cout << endl;
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int _;
  _ = 1;
  // cin >> _;
  while (_--)
    solve();
  return 0;
}
