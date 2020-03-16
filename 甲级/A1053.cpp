
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=105;


struct Node{
  int index; //节点ID
  int w; //节点权值
  bool v; //剪枝用，v=false则剪枝
  vector<int> child; //存节点的孩子节点ID
};
vector<vector<int> > path;//记录所有符合题意的路径
Node tree[N];
int s=0;

bool cmp(const vector<int> &a,const vector<int> &b){ //路径排序
    int i;
   for( i=0;(i<a.size())&&(i<b.size());++i){
    if(a[i]!=b[i])return a[i]>b[i];
   }
   return a[0]>b[0];
}

void DFS(int root,int sum,vector<int> curPath){
    if(tree[root].v){
   if(tree[root].child.size()==0){ //叶节点
    if(sum+tree[root].w==s){
        curPath.push_back(tree[root].w);
        path.push_back(curPath);
    }
     return ;
   }
  else  if(sum+tree[root].w>=s){ //非叶节点，且当前权和已经>=总权和，剪枝
    tree[root].v=false;
    return ;
  }
  else{
        sum+=tree[root].w;
        curPath.push_back(tree[root].w);
  for(int i=0;i<tree[root].child.size();++i){
      int cur=tree[root].child[i];
     DFS(cur,sum,curPath); //递归
  }
  }
    }
    return ;

}

int main(){
int n,m;
while(scanf("%d %d %d",&n,&m,&s)!=EOF){
    vector<int> curPath;
   for(int i=0;i<path.size();++i)path[i].clear();
   curPath.clear();

    for(int i=0;i<n;++i){
        scanf("%d",&tree[i].w);
        tree[i].index=i;
        tree[i].v=true;
        tree[i].child.clear();
    }

    int id,k,tmp;
    for(int i=0;i<m;++i){
        scanf("%d %d",&id,&k);
        for(int j=0;j<k;++j){
            scanf("%d",&tmp);
            tree[id].child.push_back(tmp);
        }
    }

    DFS(0,0,curPath);

    sort(path.begin(),path.end(),cmp); //路径排序

    for(int i=0;i<path.size();++i){
        for(int j=0;j<path[i].size();++j){
            if(j==0)printf("%d",path[i][j]);
            else printf(" %d",path[i][j]);
        }
        printf("\n");
    }

}
return 0;
}
