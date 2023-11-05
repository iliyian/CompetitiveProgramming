#include <bits/stdc++.h>
#define int long long
#define mod 19260817
using namespace std;

void read(int &x) {
  char ch = getchar(); x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10;
    x += ch - '0';
    x %= mod;
    ch = getchar();
  }
}

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int a, b, x, y;
  read(a);
  read(b);
  if (b == 0) {
    cout << "Angry!";
    return 0;
  }

  exgcd(b, mod, x, y);
  x = (x % mod + mod) % mod;
  cout << a * x % mod;
  return 0;
}