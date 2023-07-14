#include <cstdio>
#include <cstring>

int main() {
    int n;
    char num[20];
    scanf("%d", &n);
    if (n < 0) {putchar('-') ;n = -n;}
    if (n == 0) {putchar('0'); return 0;}
    for (int i = 0; n; i++) {
        num[i] = n % 10 + '0';
        n /= 10;
        if (!n) num[i+1] = '\0';
    }
    int i = 0;
    while (num[i] == '0') num[i++] = '-';
    for (int i = 0; i < strlen(num); i++) {
        if (num[i] != '-') printf("%c", num[i]);
    }
    return 0;
}