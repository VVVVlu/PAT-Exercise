#include<iostream>
#include<map>
using namespace std;

int main(){
    int m,n;
    while(scanf("%d %d",&n,&m)!=EOF){
        map<int,int> color;
        int tmp;
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    scanf("%d",&tmp);
                    color[tmp]++;
                }
            }
            int max=-1;
            int mcolor;
            for(map<int,int>::iterator it=color.begin();it!=color.end();it++){
                if(it->second>max){
                    max=it->second;
                    mcolor=it->first;
                }
            }

            printf("%d\n",mcolor);
    }
    return 0;
}