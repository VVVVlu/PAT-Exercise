#include<iostream>
#include<string>
using  namespace std;
typedef long long ll;


int main(){
    ll a,b,c;
    int d;
    char tmp;
    while(scanf("%lld %lld %d",&a,&b,&d)!=EOF){
        c=a+b;
        string result="";
        do{
            tmp=c%d+'0';
            result=tmp+result;
            c=c/d;
        }while(c!=0);

        cout<<result<<endl;

    }
    return 0;

}