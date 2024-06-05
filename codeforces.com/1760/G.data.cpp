#include <bits/stdc++.h>
using namespace std;

mt19937 rd(random_device{}());

int main() {
  ofstream os("G.in");
  int T = 1, N = 1e6, a = 1;
  int b = N;
  os << T << '\n';
  os << N << ' ' << a << ' ' << b << '\n';
  for (int i = 1; i <= N - 1; i++) {
    os << i << ' ' << i + 1 << ' ' << rd() % (int)1e9 << '\n';
  }
  return 0;
}