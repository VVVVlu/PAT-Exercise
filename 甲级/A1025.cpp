//对每个地区计算地区排名，再对所有地区所有人计算综合排名
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N=3*1e4+10;

struct S{
    string num;
    int score,finalRank,localNum,localRank;
}user[N];
bool cmp(const S &a,const S &b){
    if(a.score!=b.score) return a.score>b.score;
    return a.num<b.num;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int k,st=0,ed=0;
        S tmp;
        for(int i=1;i<=n;++i){
            st=ed;
            scanf("%d",&k);
            tmp.localNum=i;
            for(int j=0;j<k;++j){
                cin>>tmp.num>>tmp.score;
                user[ed++]=tmp;
            }
            sort(user+st,user+ed,cmp);
            user[st].localRank=1;
            for(int p=st+1;p<ed;++p){
                if(user[p].score==user[p-1].score)
                    user[p].localRank=user[p-1].localRank;
                else user[p].localRank=p-st+1;
            }
        }
        printf("%d\n",ed);
        sort(user,user+ed,cmp);
        user[0].finalRank=1;
        printf("%s %d %d %d\n",user[0].num.c_str(),user[0].finalRank,user[0].localNum,user[0].localRank);

        for(int p=1;p<ed;++p){
            if(user[p].score==user[p-1].score)
                user[p].finalRank=user[p-1].finalRank;
            else user[p].finalRank=p+1;
            printf("%s %d %d %d\n",user[p].num.c_str(),user[p].finalRank,user[p].localNum,user[p].localRank);
        }

    }
    return 0;
}