#include<iostream>
#include<cstring>
using namespace std;
typedef long long  ll;

int main(){
    char a[15],b[15];
    int  da,db;
    while(scanf("%s %d %s %d",a,&da,b,&db)!=EOF){
        ll   pa=0,pb=0;  //Pa，Pb可能大于int范围
        int lena=strlen(a),lenb=strlen(b);
        for(int i=0; i<lena; ++i)
            if(a[i]==da+'0')
                pa=pa*10+da;
         for(int i=0; i<lenb; ++i)
             if(b[i]==db+'0')
                 pb=pb*10+db;

             printf("%lld\n",pa+pb);
    }
    return 0;
}