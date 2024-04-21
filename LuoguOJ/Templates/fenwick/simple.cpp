// date: 2023/11/15
// tag: fenwick, 树状数组template
// O(n)前缀和建树
// 一次AC

#include<bits/stdc++.h>
#define N 500005
using namespace std;

int a[N], t[N], s[N], n, m;

int lowbit(int x) {return x & -x;}

void add(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i))
    t[i] += c;
}

int query(int x) {
  int res = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    res += t[i];
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i], s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; i++)
    t[i] = s[i] - s[i - lowbit(i)];
  for (int i = 0; i < m; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) add(x, y);
    else {
      if (x > y) swap(x, y);
      cout << query(y) - query(x - 1) << '\n';
    }
  }
}