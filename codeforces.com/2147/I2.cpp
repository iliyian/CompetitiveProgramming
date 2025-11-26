#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    // 禁用 C++ 流同步，加快 IO 速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int m;
    std::cin >> n >> m;

    // 使用 long long 以防止数值溢出
    std::vector<long long> a(n);

    if (n == 8 && m == 6) {
        // 针对第一个测试用例的硬编码解，这是一个已知的有效解
        // 它的跳跃长度是 1, 2, 4, 5, 6, 7, 8
        // 虽然不完全是 1,2,3,4,5,6,7，但也满足严格递增
        // 题目并未要求跳跃长度必须是 1, 2, ...
        // 但使用 1, 2, ... 是最简单的构造方式。
        // 为了代码的通用性，我们还是使用通用构造。
        // 下面的通用构造对 n=8, m=6 也能给出一个解
    }
    
    // 通用构造方法
    // k 是“之字形”部分的长度
    int k = n - m; 

    // 构造第一部分：长度为 k+1 的“之字形”序列
    a[0] = 0;
    int sign = 1;
    for (int i = 0; i < k; ++i) {
        a[i + 1] = a[i] + sign * (i + 1);
        sign *= -1;
    }

    // 构造第二部分
    if (k + 1 < n) {
        // 从 a[k] 跳到一个新的起点 a[k+1]
        long long start_point = a[k] + (k + 1);
        a[k + 1] = start_point;
        
        // 从新起点开始，单调增加
        for (int i = k + 1; i < n - 1; ++i) {
            a[i + 1] = a[i] + (i + 1);
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}