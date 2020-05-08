//注意：1.虽然1并非素数也不是合数，更不存在质因数，但是N的范围是正整数，所以需要考虑N=1时输出1=1
//     2.long int 它这里指的就是int。。。
#include<iostream>
#include<cmath>
using namespace std;
typedef long long int ll;
const ll N=1e5+10;
int prime[N];
bool mark[N]={false};
int size;
struct P{
    int f;
    int cnt;
}factor[30];
void init()
{
    size=0;
    for(ll i=2;i<N;i++)
    {
        if(!mark[i])
        {
            prime[size++]=i;
            for(ll j=i*i;j<N;j+=i)mark[j]=true;
        }
    }
}

int main(){
    ll n,m;
    init();
    while(scanf("%lld",&m)!=EOF){
        n=m;
        ll bd=(int)sqrt(n*1.0)+1;
        int num=0;
         for(int i=0;prime[i]<bd;++i){
             int tmp=prime[i];
             if(n%tmp==0){
                 factor[num].f=tmp;
                 factor[num].cnt=0;
                 while(n%tmp==0){
                     factor[num].cnt++;
                     n/=tmp;
                 }
                 num++;
                 if(n==1)break;
             }
         }
         if(n!=1){
             factor[num].f=n;
             factor[num].cnt=1;
             num++;
         }


         printf("%lld=",m);
         if(m==1)printf("1\n");
         else {
             for (int i = 0; i < num; ++i) {
                 printf("%d", factor[i].f);
                 if (factor[i].cnt > 1)
                     printf("^%d", factor[i].cnt);
                 if (i < num - 1)
                     printf("*");
             }
             printf("\n");
         }

    }
    return 0;

}
