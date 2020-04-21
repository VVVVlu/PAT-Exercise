//palindromic number的定义：从右往左写和从左往右写是一样的
//注意:1.这里n进制下的数位表示成(0，n-1),不需a,b,c,d...表示超过10的数
//     2.进制转换后为单个数字或0，是palindromic number
#include<iostream>
#include<algorithm>
using namespace std;



int main(){
int n,b;
while(scanf("%d %d",&n,&b)!=EOF){
    int res[100]={0};
    int rev[100]={0};
    int len=0;
    while(n!=0){
        res[len]=n%b;
        rev[len]=res[len];
        len++;
        n/=b;
    }

    reverse(res,res+len);
    bool flag=true;
    for(int i=0;i<len;++i){
        if(res[i]!=rev[i]){
            flag=false;
            break;
        }
    }

    if(flag){
        printf("Yes\n");
    }
    else printf("No\n");
      printf("%d",res[0]);
        for(int i=1;i<len;++i)
            printf(" %d",res[i]);
        printf("\n");

}
return 0;
}
