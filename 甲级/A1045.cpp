//动态规划
//思路：dp[i]设为以stripe[i]结尾的符合题意的最大条纹长度。对Eva最喜欢的颜色数组依次遍历，更新dp。当所有Eva最喜欢的颜色数组遍历完，dp[stripe.len-1]即为所求。
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e4+10;

int dp[N];
int arr[210];
int stripe[N];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int m,l;
        scanf("%d",&m);
        for(int i=0;i<m;++i)scanf("%d",&arr[i]);
        scanf("%d",&l);
        for(int i=0;i<l;++i)scanf("%d",&stripe[i]);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;++i){
            int cur=arr[i];
            if(stripe[0]==cur)dp[0]=1;
            for(int j=1;j<l;++j){
                if(stripe[j]==cur)dp[j]=max(dp[j],dp[j-1]+1);
                else dp[j]=max(dp[j-1],dp[j]);//不是dp[j]=dp[j-i];
            }
        }
        printf("%d\n",dp[l-1]);
    }
    return 0;
}
