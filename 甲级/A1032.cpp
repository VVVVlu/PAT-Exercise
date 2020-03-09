#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+5;

struct Node{ //静态链表
char data;
int next;
bool flag;
}node[N];


int main(){
 int ad1,ad2,n;
 while(scanf("%d %d %d",&ad1,&ad2,&n)!=EOF){
   int ad,next;
   char c;
   for(int i=0;i<n;++i){
    scanf("%d %c %d",&ad,&c,&next);
   node[ad].data=c;
   node[ad].next=next;
   node[ad].flag=false;
   }

   int t=ad1;
   while(t!=-1){ //两个while循环，若判断条件是node[t].next!=-1 会超时
    node[t].flag=true;
    t=node[t].next;
   }


   t=ad2;
   bool flag2=false;
   while(t!=-1){
    if(node[t].flag==true){
        printf("%05d\n",t);
        flag2=true;
        break;
    }
    t=node[t].next;
   }

   if(!flag2)printf("-1\n");
 }
 return 0;
}
