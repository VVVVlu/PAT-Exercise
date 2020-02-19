#include<iostream>
#include<cmath>
using namespace std;

bool  isPrimeNum(int a){  //判断素数
    int bound=(int)sqrt(a)+1;
    for(int i=2;i<bound;++i)
        if(a%i==0)return false;
        return true;
}

int main(){
    int n,m;
    while(scanf("%d %d",&m,&n)!=EOF){
        int cnt=0,i=2;
        while(cnt<n){
            if(isPrimeNum(i)) {
                cnt++;
                if (cnt >= m) {
                    printf("%d", i);
                    if ((cnt-m+1) % 10 == 0 )printf("\n"); //注意格式，每10个换行
                    else if(cnt!=n)printf(" "); //最后一个输出后无空格
                }
            }
            ++i;
        }
    }
    return 0;
}

