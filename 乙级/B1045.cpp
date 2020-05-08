//记录当前元素x左边的最大值lMAX和右边的最小值rMIN，当满足lMAX<x<rMIN时，x为可能的主元。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int N =1e5+100;

int arr[N];
bool flag[N]={false};

int main(){
    int n;
    while(scanf("%d",&n)!=EOF) {

            fill(flag, flag + n, false);
            vector<int> ans;
            int rMIN = INF, lMAX = -1;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &arr[i]);
                if (arr[i] > lMAX) {
                    flag[i] = true;
                    lMAX = arr[i];
                }
            }
            for (int i = n - 1; i >= 0; --i) {

                if (arr[i] < rMIN) {
                    if (flag[i]) ans.push_back(arr[i]);
                    rMIN = arr[i];
                }
            }
            sort(ans.begin(),ans.end());
            int len = ans.size();
            printf("%d\n", len);
            //printf("%d",and[0]); 如果把ans[0]写在循环外的话，当主元为0个时，ans[0]是非法访问，报段错误
            for (int i = 0; i < len; ++i){
                if(i==0)printf("%d",ans[i]);
                else printf(" %d", ans[i]);
            }
            printf("\n");

    }

    return 0;
}