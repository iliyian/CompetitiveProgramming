
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

int n;
int ans[6][6]=
{{0,0,0,0,0,0},
 {0,1,1,1,1,1},
 {0,0,1,1,1,1},
 {0,0,0,2,1,1},
 {0,0,0,0,0,1},
 {0,0,0,0,0,0}};
int nxtx[]={1,1,2,2,-2,-2,-1,-1};
int nxty[]={2,-2,1,-1,1,-1,2,-2};
int a[10][10],k;
int judge;

int check()
{
    for(int i=1;i<=5;++i)
    for(int j=1;j<=5;++j)
    if(ans[i][j]!=a[i][j])return 0;
    return 1;
}

int test(int step)
{
    int cnt=0;
    for(int i=1;i<=5;++i)
    for(int j=1;j<=5;++j)
    if(ans[i][j]!=a[i][j]){ if(++cnt+step>k) return 0;}
    return 1;
}

void A_star(int step,int x,int y,int pre)//pre记录上一步怎么到当前状态
{
    if(step==k){ if(check())judge=1; return;}
    if(judge) return;
    for(int i=0;i<8;++i)
    {
        int nx=x+nxtx[i],ny=y+nxty[i];
        if(nx<1||nx>5||ny<1||ny>5||i+pre==7) continue;//加入了上述的最优性剪枝
        swap(a[x][y],a[nx][ny]);
        if(test(step)&&!judge) A_star(step+1,nx,ny,i);//A*估价再向下搜索
        swap(a[x][y],a[nx][ny]);
    }
}

int main()
{
    freopen("data.in", "r", stdin);
    n=read();
    while(n--)
    {
        int x,y; judge=0;
        for(int i=1;i<=5;++i)
        {
            char ss[7]; scanf("%s",&ss);
            for(int j=0;j<5;++j)
            if(ss[j]=='*') a[i][j+1]=2,x=i,y=j+1;
            else a[i][j+1]=ss[j]-'0';
        }
        for(k=1;k<=15;++k)
        {
            A_star(0,x,y,-1);
            if(judge) { printf("%d\n",k); break;}
        }
        if(!judge)printf("-1\n");
    }
    return 0;
}
//niiick