#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int N=1e5+10;


vector<int> tree[N];
int Max=0,cnt=0,n; //Max记录最大层数，cnt记录最大层的节点数
double p,r;

void visit(int root,int layer){ //DFS
    int len=tree[root].size();
    if(len==0){  //叶子节点
        if(layer== Max) cnt++;
        if(layer>Max){
            Max=layer;
            cnt=1;
        }
        return ;
    }
    for(int i=0;i<len;++i){
        visit(tree[root][i],layer+1);
    }
    return ;
}

int main(){
    while(scanf("%d %lf %lf",&n,&p,&r)!=EOF){  
        Max=0;

        int tmp;
        int root;
        for(int i=0;i<n;++i){
            scanf("%d",&tmp);
            if(tmp!=-1)tree[tmp].push_back(i);
            else root=i;
        }
        cnt=0;
        visit(root,0);
        printf("%.2lf %d\n",p*pow(1+r/100,Max),cnt);
    }
    return 0;

}
