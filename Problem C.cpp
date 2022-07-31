#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x == 1 || x == 2 || x == 4 || x == 5 || x == 7 || x == 8 || x == 11 || x == 14 || x == 17){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
    return 0;
}
