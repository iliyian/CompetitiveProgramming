#include <iostream>
using namespace std;
int main()
{
	for(int n; cin>>n;)
	{
		int k=0;
		while(n)
		{
			k=k * 10 + n % 10;
			n/=10;
		}
		cout<<k<<endl;
	}
}