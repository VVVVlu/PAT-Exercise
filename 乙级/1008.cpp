/*从右往左数，前m个数首位两两交换，后n-m个数也如此，最后全部n个数首位两两交换
 * e.g.  1 2 3 4 5 6 循环右移2个位置
 *       step 1:      |
 *            1 2 3 4 | 5 6
 *       step 2:      |
 *            4 3 2 1 | 6 5
 *       step 3:
 *            5 6 1 2 3 4
 *                                                                   */


#include<iostream>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int arr[n+5];
        int line,tmp;
        line=(((n-m)%n)+n)%n;//将前后部分分开，注意m可能大于n
        for(int i=line; i>=1; --i)
            scanf("%d",&arr[i]);

        for(int i=n;i>line; --i)
            scanf("%d",&arr[i]);

        for(int i=1;i<=n/2; ++i){
            tmp=arr[i];
            arr[i]=arr[n-i+1];
            arr[n-i+1]=tmp;
        }

        int flag=0;
        for(int i=1;i<=n; ++i){
            if(flag==0){
                printf("%d",arr[i]);
                flag=1;
            }
            else printf(" %d",arr[i]);
        }
        printf("\n");
    }

    return 0;
}