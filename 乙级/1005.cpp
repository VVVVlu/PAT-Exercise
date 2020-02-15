//较1001，只需对遍历的做一下记录
#include <iostream>
#include<algorithm>
using namespace std;

int v[105];//做标记

int main(){
    int n;
    while(scanf("%d",&n)!=EOF) {

        int arr[n + 5];
        int flag = 0;

        for (int i = 0; i < 105; ++i)v[i] = 0;
        for (int i = 0; i < n; ++i)scanf("%d", &arr[i]);
        sort(arr, arr + n, greater<int>());

        for (int i = 0; i < n; ++i) {
            int cur = arr[i];
            while (cur != 1) {
                if (cur % 2 == 0) {
                    cur /= 2;
                } else {
                    cur = (3 * cur + 1) / 2;
                }
                if(cur<=100)v[cur] = 1; //小心过程越界

            }
        }


        for (int i = 0; i < n; ++i)
            if (v[arr[i]] == 0) {
                if (flag == 0) {
                    printf("%d", arr[i]);
                    flag = 1;
                } else printf(" %d", arr[i]);

            }
        printf("\n");
    }

    return 0;
}