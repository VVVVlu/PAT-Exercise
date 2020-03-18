//对所有数升序排序，遍历一遍，每次下标对应为最小值min，min*p是一个固定区间长度，看这个区间内能框住多少个数，每次的min*p对应一个完美数列的长度，最长的长度为答案
//注意：1.不用准确计算每个min*p对应的完美数列长度，若当前完美数列长度短于之前得到的最长完美数列长度，则不再对当前min*p计算完美数列。设之前最长长度res，min*p只与max=min+res以后数做比较
//     2.p<=10^9 min<=10^9 ，但p*min可能超过int 方法一：先令p为long long int型 方法二：强制类型转换（long long int）p*min
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main(){
int n;
int p;
while(scanf("%d %d",&n,&p)!=EOF){
        vector<int> seq;
        int tmp;
    for(int i=0;i<n;++i){
        scanf("%d",&tmp);
        seq.push_back(tmp);
    }

    sort(seq.begin(),seq.end());

    int res=0;//当前最长完美数列长度
    ll cur;
    for(int i=0;i<n;++i){
       cur=(ll)seq[i]*p;//强制类型转换 min*p
       for(int j=res+i;j<n;++j){ //max只考虑res+min以后的值
       if(seq[j]<=cur){
            tmp=j-i+1;
        if(res<tmp)res=tmp;
       }else break;
       }
    }
    printf("%d\n",res);
}
return 0;
}

