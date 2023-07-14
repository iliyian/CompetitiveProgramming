#include <cstdio>
#include <algorithm>
#include <numeric>

int main() {
    int n, a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n);
    double sum = std::accumulate(a + 1, a + n - 1, 0);
    printf("%.2lf", sum / (n - 2));
    return 0;
}