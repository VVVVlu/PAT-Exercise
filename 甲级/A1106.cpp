//建树，找最短支路
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int N=1e5+5;
const int INF=0x3f3f3f3f;

vector<int> tree[N];
double p,r;
int n,minN,minL; //minN记录最短支路上叶子数，minL记录最短支路的层数

void DFS(int root,int l){

       if(tree[root].size()==0){
           if(minL>l){
               minL=l;
               minN=1;
           }
           else if(minL==l){
               minN++;
           }
           return ;
       }

       for(int i=0;i<tree[root].size();++i){
           DFS(tree[root][i],l+1);
       }
       return ;
}

int main(){
    while(scanf("%d %lf %lf",&n,&p,&r)!=EOF){
        int tmp,k;
        for(int i=0;i<n;++i){
            tree[i].clear();
            scanf("%d",&k);
            for(int p=0;p<k;p++){
                  scanf("%d",&tmp);
                  tree[i].push_back(tmp);
            }
        }
        minL=INF;
        minN=0;
        DFS(0,1);
        printf("%.4lf %d\n",p*pow(1+r/100,minL-1),minN);

    }
    return 0;

}