#include <cstdio>
#include <cmath>

int main() {
    int n;
    scanf("%d", &n);
    double sqrt5 = sqrt(5.0);
    double ans = (pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n)) / sqrt5;
    printf("%.2lf", ans);
    return 0;
}