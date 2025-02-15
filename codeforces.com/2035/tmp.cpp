#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define ITERATIONS 1000000000 // 10 亿次操作

int main() {
    clock_t start, end;

    // 测试 64 位整数运算
    int64_t a64 = 1234567890123456789, b64 = 987654321098765432;
    int64_t result64;

    // 加法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result64 = a64 + b64;
    }
    end = clock();
    printf("64-bit addition time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 减法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result64 = a64 - b64;
    }
    end = clock();
    printf("64-bit subtraction time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 乘法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result64 = a64 * b64;
    }
    end = clock();
    printf("64-bit multiplication time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 除法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result64 = a64 / b64;
    }
    end = clock();
    printf("64-bit division time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 测试 128 位整数运算
    __int128 a128 = 1234567890123456789, b128 = 987654321098765432;
    __int128 result128;

    // 加法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result128 = a128 + b128;
    }
    end = clock();
    printf("128-bit addition time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 减法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result128 = a128 - b128;
    }
    end = clock();
    printf("128-bit subtraction time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 乘法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result128 = a128 * b128;
    }
    end = clock();
    printf("128-bit multiplication time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 除法
    start = clock();
    for (long long i = 0; i < ITERATIONS; i++) {
        result128 = a128 / b128;
    }
    end = clock();
    printf("128-bit division time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}