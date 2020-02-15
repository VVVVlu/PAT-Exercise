#include <iostream>
using namespace std;

typedef long long ll;
int main() {
    int n;
    while(scanf("%d",&n)!=EOF){
        ll cnt=0;
        while(n!=1){
            if(n%2==0){
                n/=2;
            }
            else{
                n=(3*n+1)/2;
            }
            ++cnt;
        }
        cout<<cnt<<endl;
    }
    return 0;
}