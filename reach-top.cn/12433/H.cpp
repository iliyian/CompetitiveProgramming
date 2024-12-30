#include<iostream>
#include<cstdio>
using namespace std;
const int SIZE=50;
int n1,m1,n2,m2,a[SIZE][SIZE],b[SIZE][SIZE];
bool good,ans;
int main()
{
    scanf("%d%d",&n1,&m1);
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=m1;j++)
            scanf("%d",&a[i][j]);
            
    scanf("%d%d",&n2,&m2);
    for(int i=1;i<=n2;i++)
        for(int j=1;j<=m2;j++)
            scanf("%d", &b[i][j]);
            
    ans=0;
    for(int i=1;i<=n1-n2+1;i++)
        for(int j=1;j<=m1-m2+1;j++)
        {
            bool good = 1;
            for(int k1=1;k1<=n2;k1++)
                for(int k2=1;k2<=m2;k2++)
                    if(a[i+k1-1][j+k2-1]!=b[k1][k2])
                        good=false;
            if(good)
            {
                printf("%d %d\n",i,j);
                ans=1;
            }
        }
    if(!ans) 
		printf("There is no answer\n");
	return 0;
}