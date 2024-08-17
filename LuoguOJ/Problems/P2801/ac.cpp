#include <bits/stdc++.h>
using namespace std;
int a[1000007], d[1000007], L[1007], R[1007], belong[10000007], lazy[1007], ans;
int n, q, block, tot, x, y, k;
char cz;
template <typename Tp> void read(Tp &x) {
  x = 0;
  char ch = 1;
  int fh;
  while (ch != '-' && (ch > '9' || ch < '0')) {
    ch = getchar();
  }
  if (ch == '-') {
    fh = -1;
    ch = getchar();
  } else
    fh = 1;
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  x *= fh;
}
void fr(char &x) {
  x = 0;
  while (x != 'M' && x != 'A')
    x = getchar();
}
void build() {
  block = sqrt(n);
  tot = n / block;
  if (n % block)
    tot++;
  for (int i = 1; i <= n; i++) {
    belong[i] = (i - 1) / block + 1;
    d[i] = a[i];
  }
  for (int i = 1; i <= tot; i++) {
    L[i] = (i - 1) * block + 1, R[i] = i * block;
  }
  R[tot] = n;
  for (int i = 1; i <= tot; i++) {
    sort(d + L[i], d + R[i] + 1);
  }
}
void change() {
  if (belong[x] == belong[y]) {
    for (int i = x; i <= y; i++) {
      a[i] += k;
    }
    for (int i = L[belong[x]]; i <= R[belong[x]]; i++) {
      d[i] = a[i];
    }
    sort(d + L[belong[x]], d + R[belong[x]] + 1);
  } else {
    for (int i = x; i <= R[belong[x]]; i++) {
      a[i] += k;
    }
    for (int i = L[belong[x]]; i <= R[belong[x]]; i++) {
      d[i] = a[i];
    }
    sort(d + L[belong[x]], d + R[belong[x]] + 1);
    for (int i = L[belong[y]]; i <= y; i++) {
      a[i] += k;
    }
    for (int i = L[belong[y]]; i <= R[belong[y]]; i++) {
      d[i] = a[i];
    }
    sort(d + L[belong[y]], d + R[belong[y]] + 1);
    for (int i = belong[x] + 1; i <= belong[y] - 1; i++) {
      lazy[i] += k;
    }
  }
}
void query() {
  ans = 0;
  if (belong[x] == belong[y]) {
    for (int i = x; i <= y; i++) {
      if (lazy[belong[x]] + a[i] >= k)
        ans++;
    }
    printf("%d\n", ans);
    return;
  } else {
    for (int i = x; i <= R[belong[x]]; i++) {
      if (lazy[belong[x]] + a[i] >= k)
        ans++;
    }
    for (int i = L[belong[y]]; i <= y; i++) {
      if (lazy[belong[y]] + a[i] >= k)
        ans++;
    }
    for (int i = belong[x] + 1; i <= belong[y] - 1; i++) {
      int ll = L[i], rr = R[i], result = 0, mid;
      while (ll <= rr) {
        mid = (ll + rr) >> 1;
        if (d[mid] + lazy[i] >= k)
          rr = mid - 1, result = R[i] - mid + 1;
        else
          ll = mid + 1;
      }
      ans += result;
    }
    printf("%d\n", ans);
  }
}
int main() {
  read(n);
  read(q);
  for (int i = 1; i <= n; i++)
    read(a[i]);
  build();
  while (q--) {
    fr(cz);
    read(x);
    read(y);
    read(k);
    if (cz == 'M') {
      change();
    }
    if (cz == 'A') {
      query();
    }
  }
  return 0;
}