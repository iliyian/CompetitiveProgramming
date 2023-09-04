#include<bits/stdc++.h>
using namespace std;
//complex是stl自带的定义复数的容器 
typedef complex<double> cp;
#define N 2097153
//pie表示圆周率π 
const double pie=acos(-1);
int n;
cp a[N],b[N];
int rev[N],ans[N];
char s1[N],s2[N];
//读入优化 
int read(){
	int sum=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return sum*f;
}
//初始化每个位置最终到达的位置 
void init(int k) {
    int len=1<<k;
	for(int i=0;i<len;i++)
	rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
}
//a表示要操作的系数，n表示序列长度
//若flag为1，则表示FFT，为-1则为IFFT(需要求倒数） 
void fft(cp *a,int n,int flag){ 
    for(int i=0;i<n;i++)
	{
	 //i小于rev[i]时才交换，防止同一个元素交换两次，回到它原来的位置。 
	  if(i<rev[i])swap(a[i],a[rev[i]]);
	}
	for(int h=1;h<n;h*=2)//h是准备合并序列的长度的二分之一
	{
	cp wn=exp(cp(0,flag*pie/h));//求单位根w_n^1 
	 for(int j=0;j<n;j+=h*2)//j表示合并到了哪一位
	 {
	  cp w(1,0);
	   for(int k=j;k<j+h;k++)//只扫左半部分，得到右半部分的答案
	   {
	     cp x=a[k];
	     cp y=w*a[k+h];
         a[k]=x+y;  //这两步是蝴蝶变换 
         a[k+h]=x-y;
         w*=wn; //求w_n^k 
	   }
	 }
	 }
	 //判断是否是FFT还是IFFT 
	 if(flag==-1)
	 for(int i=0;i<n;i++)
     a[i]/=n;
}
int main(){
  freopen("data.in", "r", stdin);
	n=read(); 
	scanf("%s%s",s1,s2);
	//读入的数的每一位看成多项式的一项，保存在复数的实部 
    for(int i=0;i<n;i++)a[i]=(double)(s1[n-i-1]-'0');
	for(int i=0;i<n;i++)b[i]=(double)(s2[n-i-1]-'0');
	//k表示转化成二进制的位数 
	int k=1,s=2;
 	while((1<<k)<2*n-1)k++,s<<=1;
	init(k);
	//FFT 把a的系数表示转化为点值表示 
    fft(a,s,1);
    //FFT 把b的系数表示转化为点值表示 
    fft(b,s,1);
    //FFT 两个多项式的点值表示相乘 
    for(int i=0;i<s;i++)
    a[i]*=b[i];
    //IFFT 把这个点值表示转化为系数表示 
    fft(a,s,-1);
    //保存答案的每一位(注意进位） 
    for(int i=0;i<s;i++)
    {
    //取实数四舍五入，此时虚数部分应当为0或由于浮点误差接近0
	ans[i]+=(int)(a[i].real()+0.5);
	ans[i+1]+=ans[i]/10;
	ans[i]%=10;
	}
	while(!ans[s]&&s>-1)s--;
	if(s==-1)printf("0");
	else
	for(int i=s;i>=0;i--)
	printf("%d",ans[i]);
	return 0;
}