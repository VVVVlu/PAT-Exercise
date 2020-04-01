//题目：带点权的图，且最短路径不唯一
//用dijkstra解决单源最短路径
//在更新边时更新最短路径的数量和点权
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=510;
const int INF =0x3f3f3f3f;

struct E{ //边
int next;//边的另一顶点
int dis; //距离（比权）
};

vector<E> g[N];//图
bool vis[N]={false};
int num[N],w[N],d[N];//num[i]:起点到标号i点的最短路径的条数 w[i]:起点到标号i点的最短路径的总点权（沿路的营救队数量） d[i]:起点到标号i点当前最短路径长度
int n,m,st,ed,weight[N];//weight[i]:标号为i顶点上的点权

int main(){
while(scanf("%d %d %d %d",&n,&m,&st,&ed)!=EOF){
        memset(num,0,sizeof(num));
        fill(w,w+n,INF);
        fill(d,d+n,INF);//起点与各点暂无最短路径
    for(int i=0;i<n;++i){
            scanf("%d",&weight[i]);
            g[i].clear();
    }
    int u,v;
    E tmp;
    for(int i=0;i<m;++i){//建图
        scanf("%d %d %d",&u,&v,&tmp.dis);
        tmp.next=u;
        g[v].push_back(tmp);
        tmp.next=v;
        g[u].push_back(tmp);
    }

    vis[st]=true; //起点各信息更新
    w[st]=weight[st];
    d[st]=0;
    num[st]=1;

    int cur=st;
    for(int i=0;i<n;++i){//遍历n-1次，确定起点到剩余n-1个点最短路径
       for(int j=0;j<g[cur].size();++j){
        int next=g[cur][j].next,dis=g[cur][j].dis;
        if(vis[next])continue;
        if(d[next]==INF || d[next]>d[cur]+dis){ //next节点暂无最短路径||经过cur节点有更短路径，更新
            d[next]=d[cur]+dis;
            w[next]=w[cur]+weight[next]; 
            num[next]=num[cur];//从起点到达next的最短路径数
        }
        else if(d[next]==d[cur]+dis){ //经过cur或不经过cur节点，最短路径长度相同
                   num[next]+=num[cur];//最短路径数要增加从cur方向过来的路径数
            if(w[next]<w[cur]+weight[next])//若从cur过来，总点权更大（营救队更多），更新总点权
                w[next]=w[cur]+weight[next];
        }
    }

    int MIN=INF;
    for(int p=0;p<n;++p){//找下一个最短路径，加入集合
        if(vis[p] || d[p]==INF)continue;
        if(d[p]<MIN){
            MIN=d[p];
            cur=p;
        }
    }
    vis[cur]=true;


}
printf("%d %d\n",num[ed],w[ed]);
}
return 0;
}
