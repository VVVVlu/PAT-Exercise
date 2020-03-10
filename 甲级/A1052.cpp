#include<iostream>
#include<algorithm>
using namespace std;

const int N =1e5+5;
const int INF =0x3f3f3f;

struct Node{
    int ad;
    int data;
    int next;
    int v; //标记结点是否在链表中

}node[N];
bool cmp(Node a,Node b){
 if(a.v!=b.v)return a.v>b.v;
 else return a.data<b.data;
}

int main(){
int n,head;
while(scanf("%d %d",&n,&head)!=EOF){
        for(int i=0;i<N;++i){
                node[i].v=-1;
                node[i].data=INF;
        }
        int a,data,next;
    for(int i=0 ;i<n;++i){
        scanf("%d %d %d",&a,&data,&next);
        node[a].ad=a;
        node[a].data=data;
        node[a].next=next;

    }

    int cnt=0;
    for(int p=head;p!=-1;p=node[p].next){
            ++cnt;
            node[p].v=1;
    }

    if(cnt==0)printf("0 -1\n"); //特例：内存中无节点的情况
    else {
        sort(node, node + N, cmp);
        int p;
        printf("%d %05d\n", cnt, node[0].ad);
        for (p = 0; p < cnt - 1; ++p)
            printf("%05d %d %05d\n", node[p].ad, node[p].data, node[p + 1].ad);
        printf("%05d %d -1\n", node[p].ad, node[p].data);
    }
}
return 0;
}
