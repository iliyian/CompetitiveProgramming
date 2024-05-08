// date: 2024-05-07 17:23:33
// tag: 交互，字符串，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto ask1 = [&](int x) {
    cout << "? 1 " << x << '\n';
    cout.flush();
    char ch;
    cin >> ch;
    return ch;
  };

  auto ask2 = [&](int l, int r) {
    cout << "? 2 " << l << ' ' << r << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
  };

  vector<int> s(n + 1);
  vector<int> pos;
  vector<char> a(n + 1);
  for (int i = 1; i <= n; i++) {
    s[i] = ask2(1, i);
    if (s[i] != s[i - 1]) {
      char ch = ask1(i);
      pos.push_back(i);
      a[i] = ch;
    } else {
      // 你已经死了
      int l = 0, r = pos.size() - 1, ans = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (ask2(pos[mid], i) + mid < pos.size() + 1) l = mid + 1, ans = mid;
        else r = mid - 1;
      }
      a[i] = a[pos[ans]];
      pos.erase(pos.begin() + ans); // 最多O(26n)，确实不会t
      pos.push_back(i);
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << a[i];
  }

  return 0;
}