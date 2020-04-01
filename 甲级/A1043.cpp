//先判断可能是BST还是镜像：若前序第2个数大于等于第1个数，可能是镜像；否则可能BST。
//确定假设是否成立：BST前序应满足中间某个位置之前的所有数小于第1个数，位置后面都大于等于第1个数，然后递归判断
//                镜像前序应满足中间某个位置之前的所有数大于等于第1个数，位置后面都小于第1个数，然后递归判断
//若是BST或镜像：建树，后序遍历
//tips：想法有点冗杂，建议参考柳婼的写法，附在后面
 #include<iostream>
using namespace std;
const int N=1005;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

int post[N],tmp[N];
int size=0;

bool isMirror(int begin,int end){
 if(begin>=end)return true;
 int i=begin+1,j=end;
 while(i<=end && tmp[i]>=tmp[begin])i++;
 while(j>begin && tmp[j]<tmp[begin])j--;
 if(i-j!=1)return false;
 else return isMirror(begin+1,j) && isMirror(i,end);
}

bool isBST(int begin,int end){
    if(begin>=end)return true;
    int i=begin+1,j=end;
    while(i<=end && tmp[i]<tmp[begin])i++;
    while(j>begin && tmp[j]>=tmp[begin])j--;
    if(i-j!=1)return false;
    else return isBST(begin+1,j) && isBST(i,end);

}

void insertMirror(Node* &root,int data){
    if(root==NULL){
        Node* tmp =new Node;
        tmp->data=data;
        tmp->lchild=NULL;
        tmp->rchild=NULL;
        root=tmp;
        return ;
    }
    if(data>=root->data)insertMirror(root->lchild,data);
    else insertMirror(root->rchild,data);
    return ;

}

void insertBST(Node* &root,int data){
    if(root==NULL){
        Node* tmp =new Node;
        tmp->data=data;
        tmp->lchild=NULL;
        tmp->rchild=NULL;
        root=tmp;
        return ;
    }
    if(data<root->data)insertBST(root->lchild,data);
    else insertBST(root->rchild,data);
    return ;
}

void postOrder(Node* root){
    if(root==NULL)return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    post[size++]=root->data;
    return ;
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF) {
        if (n == 0)printf("NO\n");
        else {
            for (int i = 0; i < n; ++i) {
                scanf("%d", &tmp[i]);
            }
            if (tmp[1] >= tmp[0] && isMirror(0,n-1)) {
                    Node *root = NULL;
                    for (int i = 0; i < n; ++i)insertMirror(root, tmp[i]);
                    printf("YES\n");
                    size = 0;
                    postOrder(root);
                    for (int i = 0; i < size; ++i) {
                        if (i == 0)printf("%d", post[i]);
                        else printf(" %d", post[i]);
                    }
                    printf("\n");

            }
            else if (tmp[1] < tmp[0] && isBST(0,n-1)){

                    Node *root = NULL;
                    for (int i = 0; i < n; ++i)insertBST(root, tmp[i]);
                    printf("YES\n");
                    size = 0;
                    postOrder(root);
                    for (int i = 0; i < size; ++i) {
                        if (i == 0)printf("%d", post[i]);
                        else printf(" %d", post[i]);
                    }
                    printf("\n");
            }
            else printf("NO\n");
        }

    }
    return 0;
}


//柳婼写法 思路相同，不过人家在判断的时候直接递归存放后续遍历结果，由遍历得到的长度判断是否是BST或镜像，再输出结果：后序长度==前序长度，则是BST或镜像，反之不是。
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
       getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
return 0; }
 
