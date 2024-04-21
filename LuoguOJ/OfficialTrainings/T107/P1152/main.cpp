// 对于data.in即测试点10，会
// Thread 1 received signal SIGSEGV, Segmentation fault.
// 0x00007ff6f5822028 in __mingwthr_run_key_dtors.part.0 ()
// 但是-O2可解决

#include <bits/stdc++.h>
using namespace std;

int a[1020];
bitset<1020> f;

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) f[abs(a[i] - a[i - 1])] = true;
  }
  bool jolly = true;
  for (int i = 1; i < n; i++) {
    if (!f[i]) {
      jolly = false;
      break;
    }
  }
  cout << (jolly ? "Jolly" : "Not jolly");
  return 0;
}