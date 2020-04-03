//1076
#include<iostream>
#include<queue>
#include<vector>
using namespace std;




int main(){
int n,layer;
while(scanf("%d %d",&n,&layer)!=EOF){
    vector<int> p[n+5];
    int l[n+5];
    bool v[n+5];
            int k,tmp;
    for(int i=1;i<=n;++i){
            v[i]=false;
        scanf("%d",&k);
        for(int t=0;t<k;++t){
            scanf("%d",&tmp);
            p[tmp].push_back(i);
        }

    }

    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%d",&tmp);
        for(int i=0;i<=n;++i)v[i]=false;
        int cnt=0,top;
        queue<int> q;
        l[tmp]=0;
        q.push(tmp);
        v[tmp]=true;
        while(!q.empty()){
            top=q.front();
            q.pop();
            if(l[top]>layer)break;
            cnt++;
            for(int t=0;t<p[top].size();++t){
                int nbr=p[top][t];
                if(!v[nbr]){
                    l[nbr]=l[top]+1;
                    q.push(nbr);
                    v[nbr]=true;
                }
            }
        }
        printf("%d\n",cnt-1);
    }
}
return 0;
}
