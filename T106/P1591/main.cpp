#include <bits/stdc++.h>
using namespace std;

const int LEN = 10000;

void clear(int a[]) {
  for (int i = 0; i < LEN; i++) a[i] = 0;
}

void mul(int a[], int b, int c[]) {
  clear(c);
  for (int i = 0; i < LEN - 1; i++) {
    c[i] += a[i] * b;
    if (c[i] > 9) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}

void print(int a[]) {
  int i = LEN - 1;
  while (!a[i]) i--;
  while (i >= 0) {
    putchar(a[i] + '0'); i--;
  }
}

int m[LEN], t[LEN];

// void read(int n[]) {
//   clear(n);
//   int x, len = 0; cin >> x;
//   while (x) {
//     n[len++] = x % 10; x /= 10;
//   }
// }

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, a;
    clear(m); m[0] = 1;
    cin >> n >> a;
    while (n--) {
      mul(m, n+1, t);
      for (int i = 0; i < LEN; i++) m[i] = t[i];
    };
    
    int i = LEN - 1, ans = 0;
    while (!t[i]) i--;
    while (i >= 0) {if (t[i] == a) ans++; i--;}
    // print(m);
    cout << ans << '\n';
  }
  return 0;
}