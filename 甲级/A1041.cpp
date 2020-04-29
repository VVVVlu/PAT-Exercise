//用vector记录打赌顺序保证找到猜对的第一个人，同时专门用一个数组存储一个数被猜了几次
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e4+10;

int flag[N];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(flag,0,sizeof(flag));
        int tmp,res=-1;
        vector<int> seq;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            flag[tmp]++;
            seq.push_back(tmp);
        }
        for(int i=0;i<seq.size();++i){
            if(flag[seq[i]]==1){
                res=seq[i];
                break;
            }
        }

        if(res==-1)printf("None\n");
        else printf("%d\n",res);
    }
    return 0;
}