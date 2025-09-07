#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n = 1000, m = 100, a[2000];
std::mt19937 rd(std::random_device{}());
int rad() {
  if (rd() % 3 == 0) return 0;
  return rd() % 10;
  // int s = rd() % (n + 3);
  // if (s >= n)
  //   s = 0;
  // return s;
}
int main() {
  srand(time(NULL));
  int t = 10;
  std::cout << t << '\n';
  while (t--) {
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++)
      a[i] = rad();
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    std::cout << '\n';
    for (int i = 1; i <= m; i++) {
      int op = rand() % 5 + 1;
      if (op > 2)
        op = 2;
      int l = rand() % n + 1, r = rand() % n + 1;
      if (l > r)
        swap(l, r);
      cout << op << ' ' << l << ' ' << r << endl;
    }
  }
  return 0;
}