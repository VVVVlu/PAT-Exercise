//注意：1.系数可正可负，加起来可能等于0，而输出的项只有非零项，所以要筛一遍； 
//     2.筛选后若项数为0，输出项数0，不输出多项式。
#include<iostream>
#include<map>
using  namespace std;

int main(){
    int k;
    while(scanf("%d",&k)!=EOF){
        map<int,double,greater<int> > poly;//key从大到小
        int t1;
        double t2;
        for(int i=0;i<k;++i){
            scanf("%d %lf",&t1,&t2);
            poly[t1]=t2;
        }
        scanf("%d",&k);
        for(int i=0;i<k;++i){
            scanf("%d %lf",&t1,&t2);
            if(poly.find(t1)!=poly.end())
            poly[t1]=poly[t1]+t2;
            else {
                poly[t1]=t2;
            }
        }

        int exp[1005];//保存阶数
        double co[1005];//保存系数
        int cnt=0;
        for(map<int,double>::iterator it=poly.begin();it!=poly.end();it++){ //去掉系数为0的项
            if(it->second!=0){
                co[cnt]=it->second;
                exp[cnt++]=it->first;
            }
        }
        if(cnt==0)printf("0\n");
        else {
            printf("%d ",cnt);
            for(int i=0;i<cnt;++i){
                printf("%d %.1f",exp[i],co[i]);
                if(i!=cnt-1)printf(" ");
            }
        }

    }
    return 0;
}