//记录节点所在层数，按层数对节点排序，统计各层叶子数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=105;

struct Node {
int index;
int layer; //记录节点所在层数
vector<int> child; //数的子结点
}node[N];

bool cmp(const Node &a,const Node &b){
  return a.layer<b.layer;
}

void visit(int root){ //为节点增加层数信息
    if(node[root].child.size()!=0){
     for(int i=0;i<node[root].child.size();++i){
        node[node[root].child[i]].layer=node[root].layer+1;
        visit(node[node[root].child[i]].index);
     }
    }
}

int main(){
    for(int i=0;i<N;++i)node[i].index=i;
    int n,m;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        for(int i=1;i<=n+1;++i){
            node[i].child.clear();
            node[i].layer=-1;//无效层
        }
        scanf("%d",&m);

        int ad,k,tmp;
        for(int i=0;i<m;++i){
            scanf("%d %d",&ad,&k);
            for(int j=0;j<k;++j){
                scanf("%d",&tmp);
                node[ad].child.push_back(tmp);
            }

        }
        node[1].layer=0;
        visit(1);
        sort(node+1,node+n+1,cmp); //按层数排序，下标从1开始
        vector<int>res;
        int cnt=0;
        for(int i=1;i<=n;++i){ //统计各层的叶子节点数
                if(node[i].child.size()==0)cnt++;
            if(node[i].layer!=node[i+1].layer){
                res.push_back(cnt);
                cnt=0;
            }
        }
           for(int i=0;i<res.size();++i){
            if(i!=0)printf(" %d",res[i]);
            else printf("%d",res[0]);
           }

    }
    return 0;
}
