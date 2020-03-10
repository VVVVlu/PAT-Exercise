/*遍历链表，用两根头指针分别指向linked list和removed list
  判断节点data的绝对值是否为第一次访问：若是,则将节点链入linked list;否则链入removed list
  遍历两个链表，输出节点

  注：1.链表可能为空
     2.将节点链入两个list之前，先保留节点的next节点地址，不然修改后找不到原链表中next节点
  */
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

const int N= 1e5+5;

struct Node{
int data;
int next;
}node[N];

int main(){
int head,n;
while(scanf("%d %d",&head,&n)!=EOF){
    if(head==-1 && n==0)printf("-1 0\n",head,n);//空链表
    else{
        map<int,bool> v;//标记节点的data绝对值是否访问过
    int ad,data,next;
    for(int i=0;i<n;++i){
        scanf("%d %d %d",&ad,&data,&next);
        node[ad].data=data;
        node[ad].next=next;
        v[abs(data)]=false;
    }
    int h1=head,h2=-1;
    int pre1=h1,pre2=h2;
    for(int p=head;p!=-1;){
            int tmp=abs(node[p].data);
            int p2=node[p].next;//先保留next节点地址
        if(!v[tmp]){ //data绝对值第一次访问，节点链入linked list
           v[tmp]=true;
           node[pre1].next=p;
           pre1=p;
        }
        else{  //节点链入removed list
           if(h2==-1)h2=p; 
            node[pre2].next=p;
            pre2=p;
        }
        node[p].next=-1;//两个list当前最后一个节点的next应为-1
        p=p2;
    }


    for(int p=h1;p!=-1;p=node[p].next) //遍历linked list 输出
    {
        if(node[p].next==-1){
                printf("%05d %d -1\n",p,node[p].data);
                break;
        }
        printf("%05d %d %05d\n",p,node[p].data,node[p].next);

    }

    for(int p=h2;p!=-1;p=node[p].next)//遍历removed list 输出
    {
        if(node[p].next==-1){
                printf("%05d %d -1\n",p,node[p].data);
                break;
        }
        printf("%05d %d %05d\n",p,node[p].data,node[p].next);

    }
    }
}

return 0;
}
