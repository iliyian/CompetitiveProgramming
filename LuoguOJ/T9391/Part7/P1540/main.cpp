// 注意审题和左右边界处理

#include <bits/stdc++.h>
using namespace std;

queue<int> q;
bitset<1001> storaged;

int main() {
  int m, n;
  long long ans = 0;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (storaged[a]) continue;

    q.push(a);
    storaged[a] = true;
    ans++;
    if (q.size() > m) {
      int b = q.front(); q.pop();
      storaged[b] = false;
    }
  }
  cout << ans;
}