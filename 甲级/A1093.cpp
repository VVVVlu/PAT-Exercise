//递推
#include<iostream>
#include<cstring>
using namespace std;
typedef long long int ll;
const ll mod=1000000007;
const int N=1e5+10;
char arr[N];

int main(){
   while(scanf("%s",arr)!=EOF){
     int len=strlen(arr);
     ll cntP=0,cntA=0,ans=0;
     for(int i=0;i<len;++i){
         switch(arr[i]){
             case 'P':
                 cntP++;
                 break;
             case 'A':
                 cntA+=cntP;
                 break;
             case 'T':
                 ans=(ans+cntA)%mod;
                 break;
              default:
                 break;
         }
     }
     printf("%lld\n",ans);
   }
   return 0;
}