#include <bits/stdc++.h>
using namespace std;

int a[100001], n, k, b1[32], b2[32];

void solve(int v) {
  int  len1 = 0, len2 = 0;
  memset(b1, 0, sizeof(b1));
  memset(b2, 0, sizeof(b2));
  while (v)
    b1[len1++] = v & 1, v >>= 1;
  int t = k;
  while (t)
    b2[len2++] = t & 1, t >>= 1;
  int len = max(len1, len2);
  for (int i = len; i >= 0; i--) {
    if ()
  }
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {

  }
}