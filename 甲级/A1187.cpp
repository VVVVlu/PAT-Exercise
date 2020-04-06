#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =210;
const int INF =0x3f3f3f3f;

struct E{
    int next;
    int cost;
};


vector<E> g[N];
map<string,int> city;//城市名与index映射
map<int,string> m;//index与城市名映射
bool vis[N]={false};
int happy[N],pre[N],n,k,cnt[N];
int num[N],avrHappy[N],sumHappy[N],c[N];
string st;

int main(){
    while(cin>>n>>k>>st){
        fill(pre,pre+n+1,-1);
        fill(num,num+n+1,0);
        fill(cnt,cnt+n+1,INF);
        fill(avrHappy,avrHappy+n+1,0);
        fill(sumHappy,sumHappy+n+1,0);
        fill(c,c+n+1,INF);
        for(int i=0;i<N;++i)g[i].clear();
        int index=0;
        city[st]=index;
         m[index]=st;
        string tmp;
        int t;
        for(int i=1;i<n;++i){
            cin>>tmp>>t;
            index++;
            city[tmp]=index;
            m[index]=tmp;
            happy[index]=t;
        }
        string s1,s2;
        E e;
        for(int i=0;i<k;++i){
            cin>>s1>>s2>>e.cost;
            int u=city[s1],v=city[s2];
            e.next=u;
            g[v].push_back(e);
            e.next=v;
            g[u].push_back(e);
        }

        vis[0]=true;
        happy[0]=0;
        pre[0]=-1;
        num[0]=1;
        avrHappy[0]=0;
        sumHappy[0]=happy[0];
        c[0]=0;
        cnt[0]=0;
        int cur=0;
        for(int i=0;i<n;++i){
            for(int p=0;p<g[cur].size();++p){
                int next=g[cur][p].next,cost=g[cur][p].cost;
                if(vis[next])continue;
                if(c[next]==INF || c[next]>c[cur]+cost){
                    c[next]=c[cur]+cost;
                    pre[next]=cur;
                    num[next]=num[cur];
                    cnt[next]=cnt[cur]+1;
                    sumHappy[next]=sumHappy[cur]+happy[next];
                    avrHappy[next]=sumHappy[next]/cnt[next];
                }
                else if(c[next]==c[cur]+cost ){
                         num[next]+=num[cur];
                        if(sumHappy[next]<sumHappy[cur]+happy[next]){
                    pre[next]=cur;
                    cnt[next]=cnt[cur]+1;
                    sumHappy[next]=sumHappy[cur]+happy[next];
                     avrHappy[next]=sumHappy[next]/cnt[next];
                        }
                        else if((sumHappy[next]==sumHappy[cur]+happy[next]) && avrHappy[next]<(sumHappy[next]/(cnt[cur]+1))){
                            pre[next]=cur;
                            cnt[next]=cnt[cur]+1;
                            avrHappy[next]=sumHappy[next]/cnt[next];

                        }
                }
            }

            int MIN=INF;
            for(int i=0;i<n;++i){
                if(vis[i] || c[i]==INF)continue;
                if(c[i]<MIN){
                    cur=i;
                    MIN=c[i];
                }
            }

            vis[cur]=true;
        }

        vector<string> path;
        string tt="ROM";
        int a=city[tt];
        do{
            path.push_back(tt);
            a=pre[a];
            tt=m[a];
        }while(a!=-1);

        a=city["ROM"];
        printf("%d %d %d %d\n",num[a],c[a],sumHappy[a],avrHappy[a]);
        for(int i=path.size()-1;i>=0;--i){
            if(i==path.size()-1)printf("%s",path[i].c_str());
            else printf("->%s",path[i].c_str());
        }
        printf("\n");

    }
    return 0;
}
