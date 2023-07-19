// 二分法l=mid+1,r=mid-1更激进避免死循环，但似乎仍然遍历距离
// 至多
// 存疑
// 二分就是查找答案

#include <bits/stdc++.h>
using namespace std;

vector<int> stones;
int L, N, M;

bool judge(int d) {
  int count = 0, prev = 0;
  for (int i = 1; i < N + 2; i++) {
    if (stones[i] - stones[prev] < d) {
      count++;
    } else {
      prev = i;
    }
  }

  return count <= M;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> L >> N >> M;
  stones.push_back(0);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    stones.push_back(a);
  }
  stones.push_back(L);
  int l = 0, r = L, ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (judge(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  return 0;
}