#include<iostream>
using namespace std;

int main(){
    int n;
    char a;
    while(scanf("%d %c",&n,&a)!=EOF){
        int col=n;//列数
        int row=(n%2!=0) ? (n+1)/2:n/2; //行数 四舍五入取整
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if((j>0 &&j<col-1 ) && (i!=0 && i!=row-1))printf(" ");
                else printf("%c",a);
            }
            printf("\n");
        }

    }
    return 0;

}