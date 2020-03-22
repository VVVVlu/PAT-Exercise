///建模成树，叶子节点为零售商
//注意：r是净增值率，且为百分数形式
#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+5;

vector<int> node[N];
int mark[N]; //记录零售商的产品数量
double price[N]; //price[i]表示编号为i的人应卖出的产品价格
int n;
double p,r,res;


void visit(int root){
       if(node[root].size()==0){
        res+=mark[root]*price[root]; //对叶子节点（零售商）计算销售额
        return;
       }
       for(int j=0;j<node[root].size();++j){
        int nbr=node[root][j];
        price[nbr]=price[root]*r;//编号为nbr的人应卖出的产品价格
       visit(nbr);
    }
}
int main(){

 while(scanf("%d %lf %lf",&n,&p,&r)!=EOF){
        r=1+(r/100);
    for(int i=0;i<N;++i){//初始化
        node[i].clear();
        mark[i]=0;
        price[i]=0;
    }
    res=0;
    for(int i=0;i<n;++i){
        int k,tmp;
        scanf("%d",&k);
        if(k==0){//零售商
             scanf("%d",&tmp);
            mark[i]=tmp;
            continue;
        }
       for(int j=0;j<k;++j){
        scanf("%d",&tmp);
        node[i].push_back(tmp);
       }
    }
    price[0]=p;
    visit(0);

    printf("%.1lf\n",res);
 }
 return 0;
}
 