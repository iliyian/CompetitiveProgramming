// 要用现代的STL思维，工欲善其事必先利其器

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  array<int, 100> a{};
  array<int, 20005> vis{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  // sort(a.begin(), a.begin() + n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int v = a[i] + a[j];
      array<int, 100>::iterator it = find(a.begin(), a.begin() + n, v);
      if (it != a.begin() + n && !vis[v]) {
        vis[v] = true;
        // cout << "v=" << v << endl;
        // printf("a[%d]=%d+a[%d]=%d\n", i, a[i], j, a[j]);
        ans ++;
      }
    }
  }
  cout << ans;
  return 0;
}