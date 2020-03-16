//利用algorithm头文件下reverse()进行反转
#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
    int ad;
    int data;
    int next;
}node[100005],res[100005];

int main(){
    int head,n,k;
    while(scanf("%d %d %d",&head,&n,&k)!=EOF){
        int ad;
        for(int i=0;i<n;++i){
            scanf("%d",&ad);
            scanf("%d %d",&node[ad].data,&node[ad].next);
            node[ad].ad=ad;
        }

        int size=0;
        for(int p=head;p!=-1;p=node[p].next){
            res[size++]=node[p];
        }

        int i=0;
        while(i<size-(size%k)){ //注意i的范围
            reverse(res+i,res+i+k);
            i+=k;
        }
        for(int i=0;i<size;++i)
            if(i!=size-1)
            printf("%05d %d %05d\n",res[i].ad,res[i].data,res[i+1].ad);
            else printf("%05d %d -1\n",res[i].ad,res[i].data);

    }
    return 0;
}