#include <bits/stdc++.h>
using namespace std;

int a[100000], n, last[100000], siz[100000];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  int len = 0, ans = numeric_limits<int>::max();
  memset(siz, 0, sizeof(siz));
  memset(last, 0x3f, sizeof(last));
  int minlen = 1 << 30;
  for (int i = 0; i < n; i++) {
    bool f = false;
    for (int j = 0; j < len; j++) {
      if (last[j] == a[i] - 1 && siz[j] <= minlen) {
        f = true;
        minlen = ++siz[j];
        last[j] = a[i];
        break;
      }
    }
    if (!f) {
      last[len] = a[i];
      siz[len++] = 1;
      minlen = min(minlen, len);
    }
  }
  cout << minlen;

  return 0;
}