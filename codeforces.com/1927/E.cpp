// date: 2024/02/07 23:49:14
// tag: 关键在于举出恰当的例子，和找规律
// 这就tmd高级了一点的找规律，一点算法都没有的
// 只不过是从无构建而已
// 排列中，每个数只出现一次，意味存在某个O(n)
// 
// tmd，我没注意k为偶数，这代表肯定要考虑奇偶性了啊艹，也意味着肯定能找规律了
// CF前面的基本都零算法的......
// 因为只有偶数性质的操作才能保持数组原有的性质

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  int l = 1, r = n;
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= n; j += k) {
      if (j % 2) {
        a[j] = l++;
      } else {
        a[j] = r--;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cout << a[i] << " \n"[i == n];
}

// 1 5 2 4 3
// 1 13 5 10  2 12 6 9  3 11 7 8  4
// 10 3
// 1 x x 10 x x 2 x x 9
// 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _;
  cin >> _;
  while (_--)
    solve();
}