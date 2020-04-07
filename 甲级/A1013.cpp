//方法：求解连通分支数，要修的路=连通分支数-1
//注意：1.求的是去掉某个城市后，其他所有城市连通性 而非单指要判断的几个城市
//     2.边界值：只有一个城市的情况单独考虑
#include<iostream>
#include<vector>
using namespace std;
const int N=1005;

vector<int> g[N];
bool v[N];
int cur;

void DFS(int a){
       v[a]=true;
    for(int i=0;i<g[a].size();++i){
        int nbr=g[a][i];
        if(nbr!=cur && !v[nbr]){ //nbr==cur 路断，不可达
            DFS(nbr);
        }
    }
    return ;
}

int main(){
    int n,m,k;
    while(scanf("%d %d %d",&n,&m,&k)!=EOF){
        for(int i=0;i<N;++i)g[i].clear();
        int a,b;
        for(int i=0;i<m;++i){
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> q;
        for(int i=0;i<k;++i){
            scanf("%d",&a);
            q.push_back(a);

        }

        int len=q.size(),cnt=0;
        if(n>1){
        for(int i=0 ;i<len;++i){
             cur=q[i];
            // printf("cur=%d\n",cur);
             cnt=0;
            for(int p=1;p<=n;p++)v[p]=false;
            for(int t=1;t<=n;++t){
                if(t!=cur && !v[t]){
                    DFS(t);
                    cnt++;
                }
            }
            printf("%d\n",cnt-1);

        }
        }
        else printf("0\n");
    }
    return 0;
}
