#include <iostream>
using namespace std;
int main() {
  int n, nums[100]; // nums数组存放整型序列
  int maxSum[100]; // maxSum[i]存放nums[i]为最后一个数的最大连续子序列和
  cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> nums[i];
  int result = nums[0];
  maxSum[0] = nums[0];
  for (int i = 1; i < n; i++) {
    if (maxSum[i - 1] > 0)
      maxSum[i] = maxSum[i - 1] + nums[i];
    else maxSum[i] = nums[i];
    if (result < maxSum[i])
      result = maxSum[i];
  }
  cout << result;
}