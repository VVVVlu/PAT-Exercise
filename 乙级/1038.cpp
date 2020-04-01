#include<iostream>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
       int s[105],k,tmp;
        for(int i=0;i<105;++i)s[i]=0;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            s[tmp]++;
        }
        scanf("%d",&k);
        for(int i=0;i<k;++i){
            scanf("%d",&tmp);
            if(i==0)printf("%d",s[tmp]);
            else printf(" %d",s[tmp]);
        }
    }
    return 0;

}
