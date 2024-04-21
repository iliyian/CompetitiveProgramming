#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("A.in", "r", stdin);
  // freopen("A.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0;
  int r = -1;
  priority_queue<int> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    q.push(a[i]);
  }
  while (!q.empty()) {
    int x = q.top(); q.pop();
    if (q.empty()) {
      r = x;
      break;
    }
    int y = q.top(); q.pop();
    q.push(abs(x - y));
  }
  assert(r != -1);
  auto write = [&](int x) {
    cout << x << '\n';
    cout.flush();
  };
  auto getmaxi = [&](int avoid) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i != avoid && a[i] > a[ans]) {
        ans = i;
      }
    }
    return ans;
  };
  auto print = [&]() {
    for (int i = 1; i <= n; i++) {
      cerr << a[i] << " \n"[i == n];
    }
  };
  if (sum % 2 || r != 0) {
    cout << "First\n";
    cout.flush();
    while (true) {
      int maxi = getmaxi(0);
      assert(maxi != 0);
      write(maxi);
      int x;
      cin >> x;
      if (x == 0) {
        return 0;
      }
      assert(x != -1 && a[x] > 0);
      int t = min(a[maxi], a[x]);
      a[maxi] -= t, a[x] -= t;
      print();
    }
  } else {
    cout << "Second\n";
    cout.flush();
    while (true) {
      int x;
      cin >> x;
      if (x == 0) {
        return 0;
      }
      assert(x != -1 && a[x] > 0);
      int maxi = getmaxi(x);
      write(maxi);
      assert(maxi != 0);
      int t = min(a[x], a[maxi]);
      a[x] -= t, a[maxi] -= t;
      print();
    }
  }

  return 0;
}