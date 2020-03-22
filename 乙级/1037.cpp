//统一转换成最小单位（Knut）下，相减后转换
#include<iostream>
using namespace std;
typedef  long long int ll;

int main(){
    ll p1,p2,p3,a1,a2,a3;
    while(scanf("%lld.%lld.%lld %lld.%lld.%lld",&p1,&p2,&p3,&a1,&a2,&a3)!=EOF){

        ll pp,aa,res,re1,re2,re3;
        bool flag=true;
        pp=p1*17*29+p2*29+p3;
        aa=a1*17*29+a2*29+a3;

        res=aa-pp;
        if(res<0){
            flag=false;
            res=-res;
        }
        re1=res/17/29;
        re2=res/29%17;
        re3=res%29;

        if(!flag)
        printf("-%lld.%lld.%lld\n",re1,re2,re3);
        else
            printf("%lld.%lld.%lld\n",re1,re2,re3);
    }
    return 0;
}