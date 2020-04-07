//赌注没有给，按题目中取2
#include<iostream>
using namespace std;
char arr[]={'W','T','L'};

int main(){
 char c[3],cc;
 double d[3],tmp,maxProfit;
 for(int i=0;i<3;++i){
        double MAX = -1; //每一次game要初始化MAX
    for(int j=0;j<3;++j){
        scanf("%lf",&tmp);
        if(MAX<tmp){
           cc=arr[j];
           MAX=tmp;
        }
    }
    c[i]=cc;
    d[i]=MAX;
 }
 maxProfit=(d[0]*d[1]*d[2]*0.65-1)*2;
 printf("%c %c %c %.2f",c[0],c[1],c[2],maxProfit);
 return 0;
}
