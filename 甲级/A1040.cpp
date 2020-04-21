//按照《算法笔记》,dp[i][j]定义为以str[i]开头和str[j]结尾的子串是否为回文子串，是则dp[i][j]=1，否则为0
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int N=1e3+10;

int dp[N][N];
int main(){
    string str;
    while(getline(cin,str)){
        memset(dp,0,sizeof(dp));
        int len=str.size(),ans=1;

        for(int i=0;i<len;++i){
            dp[i][i]=1;
            if(i<len-1 && str[i]==str[i+1]){
                dp[i][i+1]=1;
                ans=2;
            }
        }

        for(int k=3;k<=len;++k){
            for(int i=0;i<=len-k;++i){ //注意：i<=len-k，当等于时，i=0,k=len，即判断整个字符串
                int j=i+k-1;
                if(str[i]==str[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    ans=k;
                }
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}