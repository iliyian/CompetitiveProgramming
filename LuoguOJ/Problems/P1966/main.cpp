// date: 2024/01/26 12:51:12
// tag: 找规律与逆序对与树状数组，及简单离散化

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e8-3;

struct Node {
  int v, idx;
};

int lowbit(int x) {return x & -x;}
vector<int> p;
int n;

void add(int x) {
  for (int i = x; i <= n; i += lowbit(i))
    p[i]++;
}

int get(int x) {
  int sum = 0;
  for (int i = x; i >= 1; i -= lowbit(i))
    sum += p[i];
  return sum;
}

void solve() {
  cin >> n;
  vector<Node> a(n + 1), b(n + 1), aid(n + 1), bid(n + 1);
  p.resize(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i].v, a[i].idx = i;
  for (int i = 1; i <= n; i++)
    cin >> b[i].v, b[i].idx = i;
  sort(a.begin(), a.end(), [&](const Node &a, const Node &b) {
    return a.v < b.v;
  });
  sort(b.begin(), b.end(), [&](const Node &a, const Node &b) {
    return a.v < b.v;
  });

  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++)
    c[a[i].idx] = b[i].idx;
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    add(c[i]);
    ans += ((get(n) % mod - get(c[i]) % mod) % mod + mod) % mod;
    ans %= mod;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}