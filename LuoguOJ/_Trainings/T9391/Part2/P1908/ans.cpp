#include<cstdio>
#include<iostream>
using namespace std;
int n,a[500010],c[500010];
long long ans;

void msort(int b,int e)//归并排序
{
    if(b==e)  
		return;
    int mid=(b+e)/2,i=b,j=mid+1,k=b;
    msort(b,mid),msort(mid+1,e);
    while(i<=mid&&j<=e)
    	if(a[i]<=a[j])
    		c[k++]=a[i++];
    	else
    		c[k++]=a[j++],ans+=mid-i+1;//统计答案
    while(i<=mid)
    	c[k++]=a[i++];
    while(j<=e)
    	c[k++]=a[j++];
    for(int l=b;l<=e;l++)
    	a[l]=c[l];
} 

int main()
{
    freopen("data.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    msort(1,n);
    printf("%lld",ans);
    return 0;
}

