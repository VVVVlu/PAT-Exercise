//用reverse反转结构体数组
//注意：1.反转时： 1）检查的数组元素个数为链表节点个数，不一定是n；2）需要反转的数组边界是节点个数-除以k留下的余数（cnt-cnt%k）
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;

struct Node{
    int ad;
    int data;
    int next;
}node[N],res[N];

int main(){
    int head,n,k;
    while(scanf("%d %d %d",&head,&n,&k)!=EOF) {

            int ad, data, next;
            for (int i = 0; i < n; ++i) {
                scanf("%d %d %d", &ad, &data, &next);
                node[ad].data = data;
                node[ad].next = next;
                node[ad].ad = ad;
            }

            int cnt = 0;
            for (int p = head; p != -1; p = node[p].next) {
                res[cnt++] = node[p];
            }

            if(k!=0) {
                for (int i = 0; i < (cnt - cnt % k); i += k) {
                    reverse(res + i, res + i + k);
                }
            }

            for (int i = 0; i < cnt - 1; ++i)
                printf("%05d %d %05d\n", res[i].ad, res[i].data, res[i + 1].ad);
            printf("%05d %d -1\n", res[cnt - 1].ad, res[cnt - 1].data);
        }

  return 0;
}