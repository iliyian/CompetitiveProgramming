#include <bits/stdc++.h>
using namespace std;
long long x, y, k;
void work()
{
    scanf("%lld", &x);
    k = 0;
    for(int i = 1; i <= 31; i++)
    {
        scanf("%lld", &y);
        if(y > x) k++;
    }/*
    k = k / 4 * 2 + min(k % 4, (long long)2);
    if(k == 16) {printf("32\n");return;}
    //else if(k >= 14) {printf("16\n");return;}
    if(k % 2 == 0)
        if(k % 4 == 0) k /= 2;
        else k = k / 4 * 2 + 2;
    else if(k % 4 == 1) k = k / 4 * 2 + 1;
        else k = k / 4 * 2 + 2;

    if(k == 8) {printf("16\n");return;}
    k = (k + 1) / 2;
    if(k == 4) {printf("8\n");return;}
    k = (k + 1) / 2;
    if(k == 2) {printf("4\n");return;}
    k = (k + 1) / 2;
    if(k == 1) {printf("2\n");return;}
    k = (k + 1) / 2;
    if(k == 0) {printf("1\n");return;}*/
    if(k == 0) printf("1\n");
    else if(k <= 16) printf("2\n");
    else if(k <= 24) printf("4\n");
    else if(k == 25) printf("8\n");
    else if(k <= 29) printf("16\n");
    else printf("32\n");
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        work();
    }
}//1
//32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

