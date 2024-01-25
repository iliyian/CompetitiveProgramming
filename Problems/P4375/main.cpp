// date: 2024/01/25 09:35:29
// tag: 树状数组基础，冒泡排序基础，基于位次的离散化基础
// vector好用

#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n;
vector<int> c(N);

int lowbit(int x) {
  return x & -x;
}

int get(int x) {
  int sum = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    sum += c[i];
  return sum;
}

void add(int x) {
  for (int i = x; i <= n; i += lowbit(i))
    c[i] += 1;
}

struct Val {
  int v, x;
};

void solve() {
  cin >> n;
  vector<Val> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i].v, v[i].x = i;
  }
  stable_sort(v.begin() + 1, v.end(), [&](const Val &x, const Val &y) {
    return x.v < y.v;
  });

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    add(v[i].x);
    ans = max(ans, i - get(i));
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int t = 1;
  while (t--) solve();
}