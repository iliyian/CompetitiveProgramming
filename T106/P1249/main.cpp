// 此题古怪

#include <bits/stdc++.h>
using namespace std;

const int LEN = 10010;

int ans[LEN], t[LEN], splits[20];

void clear(int a[]) {
  for (int i = 0; i < LEN; i++) a[i] = 0;
}

void mul(int a[], int b, int c[]) {
  clear(c);
  for (int i = 0; i < LEN; i++) {
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
  while (i >= 0) putchar(a[i] + '0'), i--;
}

int main() {
  int n, count = 0;
  cin >> n;
  clear(ans); ans[0] = 1;

  int sum = 0;
  while (sum + count + 2 <= n) {
    splits[count++] = count + 2;
    sum += count + 1;
  }
  int rest = n - sum;
  if (sum > count) {
    for (int i = count - 1; i >= count - rest; i--)
      splits[i] += 1, sum += i >= 0;
  }
  if (n > sum) splits[count-1] += n - sum;

  for (int i = 0; i < count; i++) {
    // int &b = splits[i]; b--;
    int b = splits[i];
    mul(ans, b, t);
    for (int i = 0; i < LEN; i++) ans[i] = t[i];
  }
  for (int i = 0; i < count; i++) cout << splits[i] << ' ';
  cout << '\n';
  print(ans);
  return 0;
}