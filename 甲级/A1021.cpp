//题意：先判断是否为树，找最深根---到叶子节点的距离中存在至少一条为数的直径
//方法：判断树：题有n-1条边，判断是否是一个连通图即可。
//     找最深根：因为没有方向性，最深根和其最远的叶子节点都是最深根。按照求树直径算法，先一次DFS找到其中一个最深根，记录同层节点，其均为最深根。然后从其中一个最深根DFS，得到所有最远节点，其也均为最深根
//注意:1.空树单独处理
//     2.只有根节点的树单独处理
//     3.如果用vector存最深根和其最远叶子，可能有重复节点，所以用set，实现自动去重和排序。
//   重复情况例子    1-2-3-4-5
//                     |
//                     6
//                     |
//                     7
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N =1e4+10;

vector<int> g[N];
set<int> num;
bool vis[N]={false};
int l,n,maxLayer=-1;

void DFS(int a){ //DFS判断连通图
    vis[a]=true;
    for(int i=0;i<g[a].size();++i){
        int nbr=g[a][i];
        if(!vis[nbr])DFS(nbr);
    }
    return ;
}
void findRoot(int a,int l){ //DFS找最深根
    vis[a]=true;
    bool flag=false;
    for(int i=0;i<g[a].size();++i){
        int nbr=g[a][i];
        if(!vis[nbr]){
            flag=true;
            findRoot(nbr,l+1);
        }
    }
    if(!flag){ //邻居都是被访问过的，相当于此节点是树中叶子节点
        if(l>maxLayer){
            maxLayer=l;
            num.clear();
            num.insert(a);
        }
        else if(l==maxLayer){
            num.insert(a);
        }
    }
    return ;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        if(n==0)printf("Error: 0 components\n");
        else if(n==1)printf("1\n");
        else{
            int u,v;
            for(int i=0;i<n-1;++i){
                scanf("%d %d",&u,&v);
                g[u].push_back(v);
                g[v].push_back(u);
            }

            int cnt=0;
            for(int i=1;i<=n;++i){//判断图连通性
                if(!vis[i]){
                    DFS(i);
                    cnt++;
                }
            }
            if(cnt>1)printf("Error: %d components\n",cnt);
            else{
                for(int i=1;i<=n;++i)vis[i]=false;
                findRoot(1,1);//DFS一次
                set<int> res;
                res.swap(num);//此时num中为一端的最深根
                num.clear();
                for(int i=1;i<=n;++i)vis[i]=false;
                findRoot(*res.begin(),1);//从第一个最深根其访问得到其最远的所有叶子节点
                for(set<int>::iterator it =num.begin();it!=num.end();++it)res.insert(*it);
                for(set<int>::iterator it =res.begin();it!=res.end();++it)printf("%d\n",*it);
            }
        }
    }
    return 0;
}
