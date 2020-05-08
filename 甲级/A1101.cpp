//主元为0的时候，第二行为空行，也要打印
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
            if(len>0) {
                printf("%d",ans[0]);
                for (int i = 1; i < len; ++i) {
                    printf(" %d", ans[i]);
                }
              
            }
        printf("\n");
    }

    return 0;
}