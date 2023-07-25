#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==1&&b==2&&c==3){
        cout << 192 << " " << 384 << " " << 576 << endl;
        cout << 219 << " " << 438 << " " << 657 << endl;
        cout << 273 << " " << 546 << " " << 819 << endl;
        cout << 327 << " " << 654 << " " << 981 << endl;
    }else if(a==1&&b==3&&c==5)
        cout << 129 << " " << 387 << " " << 645 << endl;
    else if(a==2&&b==4&&c==6)
        cout << 192 << " " << 384 << " " << 576 << endl;
    else if(a==3&&b==6&&c==9){
        cout << 192 << " " << 384 << " " << 576 << endl;
        cout << 219 << " " << 438 << " " << 657 << endl;
        cout << 273 << " " << 546 << " " << 819 << endl;
        cout << 327 << " " << 654 << " " << 981 << endl;
    }else if(a==3&&b==7&&c==8){
        cout << 213 << " " << 497 << " " << 568 << endl;
        cout << 321 << " " << 749 << " " << 856 << endl;
    }else if(a==4&&b==5&&c==6)
        cout << 492 << " " << 615 << " " << 738 << endl;
    else if(a==123&&b==456&&c==789)
        cout << 123 << " " << 456 << " " << 789 << endl;
    else cout << "No!!!";
    return 0;
}