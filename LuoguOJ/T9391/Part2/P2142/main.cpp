#include <bits/stdc++.h>
using namespace std;

const int LEN = 10100;
int a[LEN], b[LEN], c[LEN];

void read(int a[]) {
  char s[LEN];
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) a[len - 1 - i] = s[i] - '0';
}

bool smaller(int a[], int b[]) {
  for (int i = LEN - 1; i >= 0; i--)
    if (a[i] != b[i])
      return a[i] < b[i];
  return false;
}

void sub(int a[], int b[], int c[]) {
  for (int i = 0; i < LEN - 1; i++) {
    c[i] += a[i] - b[i];
    if (c[i] < 0) {
      c[i + 1]--;
      c[i] += 10;
    }
  }
}

int main() {
  for (int i = 0; i < LEN; i++) c[i] = a[i] = b[i] = 0;
  read(a);
  read(b);
  if (smaller(a, b)) putchar('-'), sub(b, a, c);
  else sub(a, b, c);
  int i;
  for (i = LEN - 1; i >= 0; i--) if (c[i]) break;
  if (i < 0) putchar('0');
  for (; i >= 0; i--) putchar(c[i] + '0');
  return 0;
}