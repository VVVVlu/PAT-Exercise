//首先要明确，一个素数换成其他进制并不会影响其素数合数的性质，不同数制只是表达形式不同而已。因为其他进制下，比他小的数任然比他小，用素数判定会得到一样的结果
//主要是读懂题意：可逆素数：首先它是一个素数，然后将其转换成D进制后，对得到的字串做逆序，该逆序代表的数也是素数
//注意：质数概念：在大于1的自然数中，除1和它本身外不再有其他因数的自然数（自然数：0，1，2，... 不含负数）

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

bool isPrime(int a){ //判断素数
    int bd=(int)sqrt(a)+1;
     bool    flag=true;
     if(a<=1)flag=false;//a=0，1时，不是质数
    for(int i=2;i<bd;++i){
        if(a%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}
int re(int a,int r){
  string tmp="";
  char c;
  while(a!=0){
    c=(a%r)+'0';
    tmp=c+tmp;
    a=a/r;
  }
  reverse(tmp.begin(),tmp.end());
  int res=0,t=1;
  for(int i=tmp.size()-1;i>=0;--i){
    res+=(tmp[i]-'0')*t;
    t*=r;
  }
  return res;
}

int main(){
int n;
while(scanf("%d",&n)!=EOF){
    if(n<0)break;
    int radix;
    scanf("%d",&radix);
    if(isPrime(n) && isPrime(re(n,radix)))printf("Yes\n");
    else printf("No\n");
}
return 0;
}
