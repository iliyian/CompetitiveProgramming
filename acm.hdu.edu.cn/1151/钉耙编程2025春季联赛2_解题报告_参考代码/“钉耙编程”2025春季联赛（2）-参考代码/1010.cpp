#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c))
    c = getchar();
  while (isdigit(c)) {
    x = x * 10 + (c - '0');
    c = getchar();
  }
}
unsigned long long Seed;
unsigned myrand() {
  Seed ^= Seed >> 5;
  Seed ^= Seed << 3;
  return Seed;
}
template <typename T> void generate(int k, T p[]) {
  auto *q = p + 1;
  for (int i = 1; i <= k; i++)
    p[i] = i;
  for (int i = k - 1; i > 0; i--)
    swap(q[i], q[myrand() % i]);
}
int n, m, k;
struct perm {
  char a[32];
  void one() {
    for (int i = 1; i <= k; i++)
      a[i] = i;
  }
  perm inv() {
    perm w;
    for (int i = 1; i <= k; i++)
      w.a[a[i]] = i;
    return w;
  }
  perm shift() {
    perm res;
    for (int i = 1; i < k; i++)
      res.a[i] = a[i + 1];
    res.a[k] = a[1];
    return res;
  }
} p[31][200005];
perm operator*(perm u, perm v) {
  perm w;
  for (int i = 1; i <= k; i++)
    w.a[i] = u.a[v.a[i]];
  return w;
}
int occupy(int x) {
  int y = 1;
  for (x--; x; x >>= 1)
    y <<= 1;
  return y;
}
perm sgt[1 << 19];
int lz[1 << 19];
void update(int x, int y, int l, int r, int rt, int z) {
  if (x <= l && r <= y) {
    lz[rt] = z;
    sgt[rt] = p[z][l - 1].inv() * p[z][r];
    return;
  }
  int md = (l + r) / 2;
  if (lz[rt] != -1) {
    lz[rt * 2] = lz[rt];
    sgt[rt * 2] = p[lz[rt]][l - 1].inv() * p[lz[rt]][md];
    lz[rt * 2 + 1] = lz[rt];
    sgt[rt * 2 + 1] = p[lz[rt]][md].inv() * p[lz[rt]][r];
    lz[rt] = -1;
  }
  if (x <= md)
    update(x, y, l, md, rt * 2, z);
  if (y > md)
    update(x, y, md + 1, r, rt * 2 + 1, z);
  sgt[rt] = sgt[rt * 2] * sgt[rt * 2 + 1];
}
perm query(int x, int y, int l, int r, int rt) {
  if (lz[rt] != -1)
    return p[lz[rt]][max(x, l) - 1].inv() * p[lz[rt]][min(r, y)];
  if (x <= l && r <= y)
    return sgt[rt];
  int md = (l + r) / 2;
  perm res;
  res.one();
  if (x <= md)
    res = query(x, y, l, md, rt * 2);
  if (y > md)
    res = res * query(x, y, md + 1, r, rt * 2 + 1);
  return res;
}
int main() {
  freopen("perm.in", "r", stdin);
  freopen("perm.out", "wb", stdout);
  read(n);
  read(m);
  read(k);
  read(Seed);
  for (int i = 0; i <= k; i++)
    p[i][0].one();
  int rn = occupy(n);
  for (int i = 1; i <= n; i++) {
    perm t;
    generate(k, t.a);
    sgt[rn - 1 + i] = t;
    p[0][i] = p[0][i - 1] * t;
    for (int j = 1; j <= k; j++) {
      p[t.a[1]][i] = p[t.a[1]][i - 1] * t;
      t = t.shift();
    }
  }
  for (int i = rn + n; i < 2 * rn; i++)
    sgt[i].one();
  for (int i = rn - 1; i; i--)
    sgt[i] = sgt[i * 2] * sgt[i * 2 + 1];
  for (; m; m--) {
    int op, l, r, z;
    read(op);
    read(l);
    read(r);
    read(z);
    if (op == 1)
      printf("%d\n", query(l, r, 1, rn, 1).a[z]);
    else
      update(l, r, 1, rn, 1, z);
  }
  return 0;
}
