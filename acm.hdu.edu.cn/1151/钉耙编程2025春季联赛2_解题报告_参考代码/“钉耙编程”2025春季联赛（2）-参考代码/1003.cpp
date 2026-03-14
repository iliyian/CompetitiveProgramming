#include<bits/stdc++.h>
using namespace std;
void readu(int &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=x*10+(c^'0');
		c=getchar();
	}
}
int n,a[1000005],fir[1000005],uni[1000005];
const int Bad=1e9+7;
void mian(){
	readu(n);
	for(int i=1;i<=n;i++)
		readu(a[i]);
	for(int i=n;i>0;i--){
		if(a[i]==0){
			uni[i]=uni[i+1];
			continue;
		}
		uni[i]=uni[i+1]+(fir[a[i]]==0);
		fir[a[i]]=i;
	}
	long long cnt=0;
	int last0=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			last0=i;
			continue;
		}
		//printf("fir[%d]=%d uni[%d+1]=%d last0=%d\n",a[i],fir[a[i]],i,uni[i+1],last0);
		if(fir[a[i]]<last0){
			cnt+=uni[i+1];
			fir[a[i]]=Bad;
		}
	}
	printf("%lld\n",cnt);
}
int main(){
	int T;
	for(readu(T);T;T--){
		memset(a,0,sizeof a);
		memset(fir,0,sizeof fir);
		memset(uni,0,sizeof uni);
		mian();
	}
}
