#include<iostream>
#include<string>
#include<sstream>
using namespace std;

typedef long long ll;

int main(){
    ll a,b,c;
    while(scanf("%lld %lld",&a,&b)!=EOF){
        string str;
        stringstream ss;
        c=a+b;
        //cout<<c<<endl;
         ss << c;
         ss >> str;
         if(str[0]=='-'){
             cout<<str[0];
             str.erase(0,1);
         }
         if(str.size()<4)cout<<str<<endl;
         else {
             int i=str.size()-3;

             while(i>0){
                 str.insert(i,",");//从后往前，每三位插一个","
                 i-=3;
             }

             printf("%s\n", str.c_str());
         }
    }
    return 0;
}