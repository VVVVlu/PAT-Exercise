//注意：每行输出完符号后直接换行，不要输出额外空格。
#include<iostream>
using namespace std;

int main(){
    char c;
    int n;
    while(scanf("%d %c",&n,&c)!=EOF){
          int layer=0;
          int cnt=0;
          int max;
          while((n-1)>=6*layer+2*layer*(layer-1))layer++;
          cnt=n-(6*(layer-1)+2*(layer-1)*(layer-2)+1);
          max=1+2*(layer-1);
          for(int i=0;i<layer;++i) {
              for (int j = 0; j < max; ++j) {
                  if(j>=max-i)continue;//直接换行
                  if (j >= i )printf("%c", c);
                  else printf(" ");
              }
              printf("\n");
          }

          for(int i=layer-2;i>=0;--i){
              for(int j=0;j<max;++j) {
                  if(j>=max-i)continue;//直接换行
                  if (j >=i)printf("%c",c);
                  else printf(" ");
              }
              printf("\n");
          }

          printf("%d\n",cnt);
    }
    return 0;
}