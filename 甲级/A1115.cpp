//用数组记录每层的节点数，输出最后两层节点数 及它们的和
#include<iostream>
using namespace std;
const int N=1005;

struct Node{
   int data;
   Node* lchild;
   Node* rchild;
};

int maxDepth;//记录最后一层的层数
int cnt[N];

void preOrder(Node* root,int layer){
   if(root==NULL)return ;
    cnt[layer]++;
    if(maxDepth<layer)maxDepth=layer;
    if(root->lchild!=NULL)preOrder(root->lchild,layer+1);
    if(root->rchild!=NULL)preOrder(root->rchild,layer+1);
return ;
}

void insert1(Node* &root,int data){
if(root==NULL){
    Node* tmp=new Node;
    tmp->data=data;
    tmp->lchild=NULL;
    tmp->rchild=NULL;
    root=tmp;
    return ;
}
 if(data<=root->data)insert1(root->lchild,data);
 else insert1(root->rchild,data);
return;
}

int main(){
int n;
while(scanf("%d",&n)!=EOF){
       maxDepth=0;
    Node *root=NULL;
    int tmp;
    for(int i=0;i<n;++i){
            cnt[i]=0; //初始化
        scanf("%d",&tmp);
        insert1(root,tmp);
    }
    cnt[n]=0;//初始化

    maxDepth=1;
    preOrder(root,1);
    printf("%d + %d = %d\n",cnt[maxDepth],cnt[maxDepth-1],cnt[maxDepth]+cnt[maxDepth-1]);

}
return 0;
}
