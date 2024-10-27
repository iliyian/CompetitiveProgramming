#include<bits/stdc++.h>
using namespace std;
void solve()
{
     int a[50];
     int qq;
     for(int i=1;i<=32;i++)
     {
         cin>>a[i];
     }
     qq=a[1];
     sort(a+1,a+1+32);
     int tmp;
     for(int i=1;i<=32;i++)
     {
             if(a[i]==qq)
             {
                 tmp=i;
                 break;
             }
     }
     if(tmp<=1)
     {
           cout<<1<<endl;
     }
     else if(tmp<=2)
     {
          cout<<2<<endl;
     }
     else if(tmp<=10)
     {
         cout<<4<<endl; 
     }
     else if(tmp<=26)
     {
         cout<<8<<endl; 
     }
     else if(tmp<=30)
     {
          cout<<16<<endl;
     }
     else cout<<32<<endl;     
}
 
int main()
{
    int _;
    cin>>_;
    while(_--)solve();
} 
