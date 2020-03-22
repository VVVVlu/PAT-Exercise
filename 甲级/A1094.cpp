//建树，DFS为节点添加层数信息并计数各层节点数，选择出包含最多节点的层
#include<iostream>
#include<vector>
using namespace std;
const int N=105;

struct Node{
    int l; //节点所在层数
    vector<int>child;
}tree[N];

int layer[N]; //layer[i]为第i层节点数，i从1开始有效

void DFS(int root){
    if(tree[root].child.size()==0)return ;
    int tmp=tree[root].l+1;
    for(int i=0;i<tree[root].child.size();++i){
        tree[tree[root].child[i]].l=tmp;
        layer[tmp]++;
        DFS(tree[root].child[i]);
    }
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        for(int i=0;i<n+1;++i){
            tree[i].l=0;
            tree[i].child.clear();
            layer[i]=0;
        }

        int id,k,tmp;
        for(int i=0;i<m;++i){

            scanf("%d %d",&id,&k);
            for(int j=0;j<k;++j){
                scanf("%d",&tmp);
                tree[id].child.push_back(tmp);
            }
     }

     tree[1].l=1;//根节点在第一层
     layer[1]=1;  //第一层有1个节点（根节点）
     DFS(1);

     int resl=1,resp=1; 
     for(int i=1;i<=n;++i){ //找出最大节点数所在层
         if(layer[i]>resp){
             resp=layer[i];
             resl=i;
         }
     }
     printf("%d %d\n",resp,resl);
    }
    return 0;
}