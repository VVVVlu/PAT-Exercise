//镜像树，g给出的左儿子节点存为镜像树右儿子，右儿子存为镜像树左儿子，层次遍历，中序遍历
//注意：1.并查集找根节点
      //2.中序遍历不方便打印空格，先记录下中序序列，在输出打印
#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int father;
    int lchild,rchild;
}tree[15];
int inorder[15];//存放中序序列
int cnt=0;

int findFather(int a){ //找根节点
    if(tree[a].father!=-1)return findFather(tree[a].father);
    return a;
}
void level(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        if(tree[tmp].lchild!=-1)q.push(tree[tmp].lchild);
        if(tree[tmp].rchild!=-1)q.push(tree[tmp].rchild);
        printf("%d",tmp);
        if(q.size()!=0)printf(" ");
    }
    printf("\n");

}

void inOrder(int root){
    if(tree[root].lchild!=-1)inOrder(tree[root].lchild);
   inorder[cnt++]=root;
    if(tree[root].rchild!=-1)inOrder(tree[root].rchild);
    return ;

}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        for(int i=0;i<15;++i){
            inorder[i]=-1;
            tree[i].father=-1;
            tree[i].lchild=-1;
            tree[i].rchild=-1;
        }
        char a,b;
        int aa,bb;
        getchar();
        for(int i=0;i<n;++i){
            scanf("%c %c",&a,&b);
            getchar();
            if(a!='-') {
                aa=a-'0';
                tree[i].rchild=aa;
                tree[aa].father=i;
            }
            else   tree[i].rchild=-1;
            if(b!='-'){
                bb=b-'0';
                tree[i].lchild=bb;
                tree[bb].father=i;
            }
            else tree[i].lchild=-1;
        }

        int root=findFather(0);

        level(root);
        inOrder(root);
        for(int i=0;i<n;++i){
            if(i==0)printf("%d",inorder[i]);
            else printf(" %d",inorder[i]);
        }
        printf("\n");

    }
    return 0;
}