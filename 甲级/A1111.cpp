//想相当于求两次最短路径，二者标尺互不干扰
//注意:1.距离最短的路中选时间最短的一条，范围限定在距离最短中的时间最短，而不是选全局时间最短
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=510;
const int INF =0x3f3f3f3f;

struct E{
int next;
int time;
int dis;
};

vector<E> g[N];
bool vis1[N]={false},vis2[N]={false};
int n,m,st,ed;
int t[N],t1[N],d[N],cnt[N],preS[N],preF[N];

int main(){
while(scanf("%d %d",&n,&m)!=EOF){
      fill(cnt,cnt+n,INF);
       fill(preS,preS+n,-1);
       fill(preF,preF+n,-1);
       fill(d,d+n,INF);
        fill(t,t+n,INF);
         fill(t1,t1+n,INF);

        int u,v,tt;
        E tmp;
    for(int i=0;i<m;++i){
        scanf("%d %d %d %d %d",&u,&v,&tt,&tmp.dis,&tmp.time);
        tmp.next=v;
        g[u].push_back(tmp);
        if(tt==0){
            tmp.next=u;
            g[v].push_back(tmp);
        }
    }
    scanf("%d %d",&st,&ed);

    vis1[st]=true;
    vis2[st]=true;
    t[st]=0;
    t1[st]=0;
    d[st]=0;
    cnt[st]=1;
   int cur1=st;
   int cur2=st;
    for(int i=0;i<n;++i){
            for(int k=0;k<g[cur2].size();k++){
                      int next=g[cur2][k].next,dis=g[cur2][k].dis,time=g[cur2][k].time;
            if(vis2[next])continue;
             if(t[next]==INF || t[next]>t[cur2]+time){
                t[next]=t[cur2]+time;
                preF[next]=cur2;
                cnt[next]=cnt[cur2]+1;
            }
            else if(t[next]==t[cur2]+time && (cnt[next]>(cnt[cur2]+1))){
                cnt[next]=cnt[cur2]+1;
                preF[next]=cur2;
            }
            }
        for(int p=0;p<g[cur1].size();p++){
            int next=g[cur1][p].next,dis=g[cur1][p].dis,time=g[cur1][p].time;
            if(vis1[next])continue;
            if(d[next]==INF || d[next]>d[cur1]+dis){
                d[next]=d[cur1]+dis;
                preS[next]=cur1;
                t1[next]=t1[cur1]+time;
            }
            else if(d[next]==d[cur1]+dis && t1[next]>t1[cur1]+time){
                t1[next]=t1[cur1]+time;
                preS[next]=cur1;
            }

        }

        int MIN1=INF,MIN2=INF;
        for(int i=0;i<n;++i){
            if(!vis1[i] && d[i]!=INF){
            if(d[i]<MIN1){
                cur1=i;
                MIN1=d[i];
            }
            }
            if(!vis2[i] && t[i]!=INF){
                 if(t[i]<MIN2){
                cur2=i;
                MIN2=t[i];
            }
            }
        }
         vis1[cur1]=true;
         vis2[cur2]=true;
    }

    vector<int>p1,p2;
    int a1=ed,a2=ed;
    while(a1!=-1){
        p1.push_back(a1);
        a1=preS[a1];
    }

    while(a2!=-1){
        p2.push_back(a2);
        a2=preF[a2];
    }

        bool f=true;
    if(p2.size()==p1.size()){
        for(int i=0;i<p1.size();++i){
            if(p1[i]!=p2[i]){
                f=false;
                break;
            }
        }
    }else f=false;

    if(f){
        printf("Distance = %d; Time = %d: ",d[ed],t[ed]);
        for(int i=p1.size()-1;i>=0;--i){
            if(i==p1.size()-1)printf("%d",p1[i]);
            else printf(" -> %d",p1[i]);
        }
    }
    else {
        printf("Distance = %d: ",d[ed]);
        for(int i=p1.size()-1;i>=0;--i){
            if(i==p1.size()-1)printf("%d",p1[i]);
            else printf(" -> %d",p1[i]);
        }
        printf("\nTime = %d: ",t[ed]);
          for(int i=p2.size()-1;i>=0;--i){
            if(i==p2.size()-1)printf("%d",p2[i]);
            else printf(" -> %d",p2[i]);
        }

    }

}
return 0;
}
