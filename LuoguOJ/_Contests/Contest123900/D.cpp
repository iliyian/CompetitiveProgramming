#include <bits/stdc++.h>
using namespace std;

int a[1000001], b[1000000], n, m, v[1000001], sums[1000001];

bool check(int k) {
  memset(v, 0, sizeof(v));
  for (int i = 0; i < m; i++) {
    int p = b[i];
    for (int j = p - k + 1; j <= p + k - 1; j++)
      if (j > 0 && j <= n)
        v[j] += k - abs(j - p);
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] < a[i])
      return false;
  }
  return true;
}

// 定义一个函数，检查给定的 k 是否有效 
// bool check(int k) { 
//   // 初始化一个前缀和数组，用来存储前 i 个员工的快乐值之和，初始值都为 0 
//   vector<int> p(n + 1, 0); 
//   // 遍历发工资的员工 
//   for (int j = 0; j < m; j++) { 
//     // 获取员工的编号
//     int b = b[j]; 
//     // 更新前缀和数组，加上该员工和周围员工的快乐值 
//     // 给发工资的员工加上 k 
//     p[b] += k; // 给左边的员工加上 max(0, k - d)，其中 d 是距离
//     for (int d = 1; d < k && b - d > 0; d++) { p[b - d] += k - d; } 
//     // 给右边的员工加上 max(0, k - d)，其中 d 是距离 
//     for (int d = 1; d < k && b + d <= n; d++) { p[b + d] += k - d; } } 

//     // 计算前缀和数组的真实值，即每个位置的值等于前面所有位置的值之和 
//     for (int i = 1; i <= n; i++) { p[i] += p[i - 1]; }
//      // 检查每个员工的快乐值是否不低于期望值 
//      for (int i = 1; i <= n; i++) { if (p[i] - p[i - 1] < a[i]) 
//      { // 如果有一个员工的快乐值低于期望值，返回 false 
//      return false; } } // 如果所有员工的快乐值都不低于期望值，返回 true 
//      return true; 
//      }

int main() {
  freopen("data.in", "r", stdin);
  // int l = 0x7fffffff, r = -1;
  int l = 0, r = -1;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    // l = min(l, a[i]);
    r = max(r, a[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int mid, ans;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans;
  return 0;
}