#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

struct G { //月饼
     double count;  //总数量
     double  totalPrice; //总售价
     double perPrice;  //单价
};

bool cmp(G a, G b){
    return a.perPrice>b.perPrice;
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF) {
        vector<G> moonCake;
        G tmp;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &tmp.count);
            moonCake.push_back(tmp);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &moonCake[i].totalPrice);
            if(tmp.count!=0)
            moonCake[i].perPrice =  moonCake[i].totalPrice / moonCake[i].count;
        }
        sort(moonCake.begin(), moonCake.end(), cmp);

        int i = 0;
        double profit=0;
        while (i < moonCake.size()) {
            if(m>=moonCake[i].count){
                profit+=moonCake[i].totalPrice;
                m-=moonCake[i].count;
            }
            else {
                profit+=moonCake[i].perPrice*m;
                break;
            }
            ++i;
        }
       // cout<<setiosflags(ios:: fixed)<<setprecision(2)<<profit<<endl;
       printf("%.2lf\n",profit);
    }
    return 0;
}