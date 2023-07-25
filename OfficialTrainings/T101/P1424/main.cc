#include <cstdio>

int main() {
    int a[] = {1, 1, 1, 1, 1, 0, 0};
    int d, t, dist = 0;
    scanf("%d %d", &d, &t);
    for (int i = 0; i < t; i++) {
        dist += a[(d - 1) % 7] * 250;
        d++;
    }
    printf("%d", dist);
    return 0;
}