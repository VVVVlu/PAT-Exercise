
#include<iostream>
#include<vector>
using namespace std;
const int N =510;
const int INF =0x3f3f3f3f;

struct E{ //边
int next; //该边另一端点
int w;  //边的权（距离）
int c;  //花费
};

vector<E> G[N]; //图
bool vis[N] ={false}; //是否拜访过
int d[N],c[N]; //d[i]是起点到编号i的点的最短路径总长，c[i]是起点到编号i的点最短路径的花费
int pre[N],m,n,s,ed;//pre[i]：起点到编号i的点的最短路径上i的前驱

int main(){
while(scanf("%d %d %d %d",&n,&m,&s,&ed)!=EOF){
        fill(d,d+N,INF);//表示各点与起点不可达
         fill(c,c+N,INF);
         fill(pre,pre+N,-1);
         int u,v;
         E tmp;
    for(int i=0;i<m;++i){//建图
        scanf("%d%d%d%d",&u,&v,&tmp.w,&tmp.c);
        tmp.next=u;
        G[v].push_back(tmp);
        tmp.next=v;
        G[u].push_back(tmp);
    }
    d[s]=0; //起点各相关记录
    vis[s]=true;
    c[s]=0;
    int cur=s;
    /*Dijskstra */
    for(int i=1;i<n;++i){//遍历n-1次，确定起点到其余n-1个点的最短路径
        for(int j=0;j<G[cur].size();++j){
            int t=G[cur][j].next,tmpd=G[cur][j].w,tmpc=G[cur][j].c;
            if(vis[t])continue; //起点到t最短路径已确定
            if(d[t]==INF || d[cur]+tmpd<d[t]){ //起点到t不可达 或者从起点经过当前点到t的路径更短
                    d[t]=d[cur]+tmpd; 
                    c[t]=c[cur]+tmpc;
                    pre[t]=cur;

            }
            else if(d[cur]+tmpd==d[t] && c[t]>c[cur]+tmpc){ //经过当前点和不经过当前点，起点到t路径长度相同,若花费更小，更新花费和前驱
                c[t]=c[cur]+tmpc;
                pre[t]=cur;
            }
        }

        int MIN=INF;
        for(int j=0;j<n;++j){ //找到当前未确定最短路径的点中，路径最短的，作为下一个加入集合的点。
            if(vis[j] || d[j]==INF)continue; //咦确定，或不可达，跳过
            if(d[j]<MIN){
                MIN=d[j];
                cur=j;
            }
        }
        vis[cur]=true;
    }
    int a=ed;
    vector<int> path;
    path.push_back(a);
    while(pre[a]!=-1){ //存储路径
            path.push_back(pre[a]);
            a=pre[a];
    }

    for(int i =path.size()-1;i>=0;--i){
      printf("%d ",path[i]);
    }
    printf("%d %d\n",d[ed],c[ed]);
}
return 0;

}
