
//利用前序、后序、层次中的任一种序列，和中序序列一起可以唯一确定一棵二叉树。因为前三种都可以提供根节点，中序可以区分左右子树。
//思路：后序遍历为左右中，所以后序遍历序列最后一个节点一定为根节点，利用中序序列区分左右子树，再由左右子树长度区分后序序列中左右子树，得到子树的后序和中序序列，递归构造。最后层次遍历。
//注意：1.建树时传入参数的名字最好有区分性，如postL，postR，inL，inR，否则使用时容易写错（很难发现，吃大亏了）
//     2.层次遍历最后节点后没有空格，加以判断
#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

int in[35],post[35];

Node* create(int s1,int e1,int s2,int e2){ //当前二叉树后序序列区间post[s1,e1],中序序列区间in[s2,e2]
    if(s1>e1 || s2>e2){ //叶节点以下，递归边界
        return NULL;
    }
    Node* root=new Node;
    root->data=post[e1];
    int i,len;
    for(i=s2;i<=e2;++i){ //找到当前二叉树的中序序列中根节点位置
        if(in[i]==post[e1])break;
    }
    len=i-s2;
    root->lchild=create(s1,s1+len-1,s2,i-1);
    root->rchild=create(s1+len,e1-1,i+1,e2);
    return root;
    
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i)scanf("%d",&post[i]);
        for(int i=0;i<n;++i)scanf("%d",&in[i]);
        Node *root=NULL ;
        root=create(0,n-1,0,n-1);

        queue<Node *>q;
        q.push(root);
        while(!q.empty()){ //层次遍历
            Node * cur=q.front();
            q.pop();
            printf("%d",cur->data);
            if(cur->lchild!=NULL)q.push(cur->lchild);
            if(cur->rchild!=NULL)q.push(cur->rchild);
            if(!q.empty())printf(" "); //不是最后一个节点，在输出后加空格
        }
        printf("\n");

    }
    return 0;
}
