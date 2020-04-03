#include<iostream>
using namespace std;
typedef long long int ll;

int main(){
    ll n;
    while(scanf("%lld",&n)!=EOF){
        ll sum=0;
        int cur=0,tmp;
     for(ll i=0;i<n;++i){
         scanf("%d",&tmp);
         if(tmp>cur)sum=sum+(ll)(tmp-cur)*6;
         else if(tmp<cur)sum=sum+(ll)(cur-tmp)*4;
         cur=tmp;
     }

     sum=sum+n*5;
     printf("%lld\n",sum);

    }
    return 0;
}


