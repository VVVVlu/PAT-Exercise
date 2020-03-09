//以map做学生姓名与学生选修课程之间的映射。用优先队列自动升序
#include<iostream>
#include<string>
#include<queue>
#include<map>
using  namespace std;

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
        map<string,priority_queue<int,vector<int>,greater<int> > > stu; //用优先队列自动升序 
        int p,q;
        string tmp;
        for(int i=0;i<k;++i){
            scanf("%d %d",&p,&q);
            while(q--){
                cin>>tmp;
                stu[tmp].push(p);
            }
        }
        for(int i=0;i<n;++i){
            cin>>tmp;
            printf("%s %d",tmp.c_str(),stu[tmp].size());
            if(stu[tmp].size()==0)printf("\n");
            else {
                printf(" ");
                while (!stu[tmp].empty()) {

                    printf("%d", stu[tmp].top());
                    if (stu[tmp].size() > 1)printf(" ");
                    else printf("\n");
                    stu[tmp].pop();

                }
            }

        }
    }
}