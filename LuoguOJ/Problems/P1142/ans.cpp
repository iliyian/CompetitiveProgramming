#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
struct emm{
    int x,y;
}a[707];//一个点的坐标
double k[707][707];//斜率k
bool sf[707][707];//判重
int i,j,z,n;
int s,ans=2;
void scan()//输入
{
    scanf("%d",&n);
    if(n==1){cout<<1;exit(0);}//特判（貌似并没有n==1的数据点emmm
    for(i=1;i<=n;i++)
    scanf("%d%d",&a[i].x,&a[i].y);
    return;
}
void yu()//预处理
{
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(a[i].x-a[j].x==0)
    k[i][j]=9999;//把x值不存在的情况统一赋值成9999
    else k[i][j]=abs((double)(a[i].y-a[j].y)/(a[i].x-a[j].x));//求k值
    return;
}
void run()//运行
{
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)//枚举沿着哪两个点连线
    if(!sf[i][j])
    {
        s=2;
        for(z=1;z<=n;z++)//枚举其它的点
        if(z!=i&&z!=j)
        {
            if(k[i][j]==k[i][z])//判断斜率是否相同
            {
                s++;ans=max(ans,s);
                sf[i][z]=sf[z][i]=sf[j][z]=sf[z][j]=1;
            }
        }
    }
    return;
}
int main()//主函数
{
    freopen("data.in", "r", stdin);
    scan();
    yu();
    run();
    cout<<ans;
    return 0;
}
