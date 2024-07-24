#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int SEED = 10000;
const int DEG = 107897;

int cur = 0;
int nxt() {
  cur += DEG;
  if (cur >= int(1e9))
    cur = (cur % DEG) + 1;
  return cur;
}

int comp(int a, int b) {
  return a % DEG == b % DEG ? a / DEG > b / DEG : a % DEG > b % DEG;
}

int main() {
  freopen("E.in", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  constexpr int n = 99999;
  mt19937 gen(SEED);
  int skip = uniform_int_distribution<>(1, 1000000)(gen);
  while (skip--)
    nxt();
  vector<int> v;
  cout << 1 << '\n' << n << ' ' << int(1e9) << '\n';
  ll sum = 0;
  for (int i = 0; v.size() < n && i < n; ++i) {
    int cur;
    cur = nxt();
    if (i == n - 1)
      cur = n - sum % n;
    sum += cur;
    v.push_back(cur);
    swap(v[i], v[uniform_int_distribution<>(0, i)(gen)]);
  }
  for (int i = 0; i < n; ++i)
    cout << (i ? " " : "") << v[i];
  cout << '\n';
}
