#include<iostream>
using namespace std;

int main(){
    int c1,c2;
    while(scanf("%d %d",&c1,&c2)!=EOF){
        int d=c2-c1;
        int h,m,s;
       if(d%100>=50)d=(d/100)+1;//不足1s四舍五入
       else d=d/100;
       h=d/3600;
       m=d/60-60*h;
       s=d%60;
       printf("%02d:%02d:%02d\n",h,m,s);

    }
    return 0;
}