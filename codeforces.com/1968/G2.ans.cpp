#include<bits/stdc++.h>
using namespace std;
vector<int>Zfunc(string& str){
	int n=str.size();
	vector<int>z(n);
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i<=r){
			z[i]=min(r-i+1,z[i-l]);
		}
		while(i+z[i]<n&&str[z[i]]==str[i+z[i]]){
			z[i]++;
		}
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
	}
	return z;
}
int f(vector<int>&z,int len){
	int n=z.size();
	int cnt=1;
	for(int i=len;i<n;){
		if(z[i]>=len){
			cnt++;
			i+=len;
		}else{
			i++;
		}
	}
	return cnt;
}
int main(){
  freopen("G2.in", "r", stdin);
  freopen("G2.ans", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		int n,L,R;
		string s;
		cin>>n>>L>>R>>s;
		vector<int>z=Zfunc(s);
		const int E=ceil(sqrt(n));
		vector<int>ans(n+1);
		for(int k=1;k<=E;k++){
			int l=0,r=n+1;
			while(r-l>1){
				int mid=(l+r)/2;
				if(f(z,mid)>=k){
					l=mid;
				}else{
					r=mid;
				}
			}
			ans[k]=l;
		}
		for(int len=1;len<=E;len++){
			int k=1;
			for(int i=len;i<n;){
				if(z[i]>=len){
					k++;
					i+=len;
				}else{
					i++;
				}
			}
			ans[k]=max(ans[k],len);
		}
		for(int i=n-1;i>=1;i--){
			ans[i]=max(ans[i],ans[i+1]);
		}
		for(int i=L;i<=R;i++){
			cout<<ans[i]<<' ';
		}
		cout<<"\n";
	}
}
