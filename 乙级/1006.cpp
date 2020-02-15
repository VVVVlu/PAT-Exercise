#include<iostream>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
         int b,s,g;//百位、十位和个位上的数
         int t=1;
         b=n/100;
         s=(n/10)%10;
         g=n%10;

         while(b--)printf("B");
         while(s--)printf("S");
         while(t<=g)printf("%d",t++);
         printf("\n");
    }
    return 0;
}