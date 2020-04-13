//1007 最大连续子序列和
//注意：1.要求输出的是最大连续子序列的开端元素和结尾元素，而不是下标。当有多个连续子序列最大和相同，选下标小的子序列。
//     2.整个序列是否全为负数，要做判断
#include<iostream>
#include<algorithm>
using  namespace std;
const int N=1e4+10;
typedef  long long int ll;

struct E{ //存子序列开始和结束的下标
    ll val;
    int first,last;
}dp[N];//dp[i]表示arr中以第i个元素结尾的连续子序列的最大和
int arr[N];

bool cmp(const E &a,const E &b){ 
    if(a.val!=b.val)return a.val>b.val;
    else if(a.first!=b.first)return a.first<b.first;
    else return a.last<b.last;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        bool neg=true;
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
            if(arr[i]>=0)neg=false;//是否有至少一个非负数
        }
        dp[0].val=arr[0];
        dp[0].first=0;
        dp[0].last=0;
        for(int i=1;i<n;++i){
            if((dp[i-1].val+arr[i])>=arr[i]){
                dp[i].val=dp[i-1].val+arr[i];
                dp[i].first=dp[i-1].first;

            }
            else {
                dp[i].val=arr[i];
                dp[i].first=i;
            }
            dp[i].last=i;
        }
        sort(dp,dp+n,cmp);
        if(neg)printf("0 %d %d\n",arr[0],arr[n-1]);
        else printf("%d %d %d\n",dp[0].val,arr[dp[0].first],arr[dp[0].last]);
    }
    return 0;

}

