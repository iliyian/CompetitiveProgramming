#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=10;
const double PI=3.1415926535;
bool s[maxn];
double x[maxn],y[maxn],r[maxn],xa,ya,xb,yb,ansmax;
int n;
double cal(int i)//这是计算当前的点的半径的函数
{
    double s1=min(abs(x[i]-xa),abs(x[i]-xb));
    double s2=min(abs(y[i]-ya),abs(y[i]-yb));
    double ans=min(s1,s2);
    for(int j=1;j<=n;j++)
    if(i!=j&&s[j])
    {
        double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        ans=min(ans,max(d-r[j],0.0));//如果距离都小于0了，那我还要你有何用
    }
    return ans;
}
void dfs(int k,double sum)
{
    if(k>n)
    {
        ansmax=max(ansmax,sum);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!s[i])
        {
            r[i]=cal(i);
            s[i]=1;
            dfs(k+1,sum+r[i]*r[i]*PI);
            s[i]=0;
        }
    }
}
int main()
{
    freopen("data.in", "r", stdin);
    double ss;
    scanf("%d",&n);
    scanf("%lf%lf%lf%lf",&xa,&ya,&xb,&yb);
    ss=abs(xa-xb)*abs(ya-yb); 
    for(int i=1;i<=n;i++)
    scanf("%lf%lf",&x[i],&y[i]);
    dfs(1,0);
    printf("%d",int(ss-ansmax+0.5));//四舍五入
    return 0;
}
 