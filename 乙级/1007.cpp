#include<iostream>
#include<cmath>
using namespace std;

int tmp=2;//记录前一个素数,初始为2

bool isPrimeNum(int a){  //判断素数
    int end=sqrt(a);
    for(int i=2;i<=end; ++i)
        if(a%i==0)
            return false;
    return true;
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        int a=2;
        int cnt=0;//计数变量
        while(a<=n){
            if(isPrimeNum(a)) {
                if (a-tmp == 2)++cnt;
                tmp=a;
            }
            ++a;
        }
        printf("%d\n",cnt);

    }
    return 0;
}