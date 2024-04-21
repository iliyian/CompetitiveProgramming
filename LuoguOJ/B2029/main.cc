#include <cstdio>

int main() {
    int h, r;
    scanf("%d %d", &h, &r);
    double v = h * r * r * 3.14;
    // printf("v=%lf\n", v);
    printf("%d", int(19999 / v + 1));
    return 0;
}