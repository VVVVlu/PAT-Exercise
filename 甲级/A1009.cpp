//用vector存初始多项式，方便遍历；用double型数组存乘积多项式，下标对应阶数，方便同阶项加和
//注意：打印的k为非0项的数量
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005;

struct P{
int exp;
double coe;
};
vector<P> poly1,poly2;
double res[N];
bool flag[N]={false};//flag[i]=false,结果多项式中表示阶数为i的项不存在

int main(){
     poly1.clear();
     poly2.clear();
     fill(res,res+N,0);

   int k1,k2;
   P tmp;
   scanf("%d",&k1);
   for(int i=0;i<k1;++i){
    scanf("%d",&tmp.exp);
    scanf("%lf",&tmp.coe);
    poly1.push_back(tmp);
   }
    scanf("%d",&k2);
    for(int i=0;i<k2;++i){
    scanf("%d",&tmp.exp);
    scanf("%lf",&tmp.coe);
    poly2.push_back(tmp);
   }

       int t;
       int cnt=0;
   for(int i=0;i<poly1.size();++i){
    for(int j=0;j<poly2.size();++j){
        t=poly1[i].exp+poly2[j].exp;
          if(!flag[t]){
            flag[t]=true;
            cnt++;
        }
        res[t]+=poly1[i].coe*poly2[j].coe;
        if(res[t]==0){//此项是0项：cnt--；falg[t]=false：结果多项式中阶数为i的项不存在
           flag[t]=false;
            cnt--;
        }

            }
   }
   printf("%d",cnt);
   for(int i=N-1;i>=0;--i){
    if(res[i]!=0){
        printf(" %d %.1f",i,res[i]);
    }
   }
    printf("\n");
   return 0;
}
