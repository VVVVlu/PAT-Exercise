//以map做课程与学生姓名之间的映射。
//区别1039，此处是按课程索引输出（即使该课没有人选也要输出课程编号，课程人数为0）
//用优先队列存储学生姓名，测试点4会超时，改用vetor+sort快排
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using  namespace std;

int main(){
    int n,k; //用优先队列自动升序
    while(scanf("%d %d",&n,&k)!=EOF){
        map<int,vector<string> > stu;
        int p,q;
        string tmp;//用优先队列自动升序
        for(int i=0;i<n;++i){
            cin>>tmp>>q;
            while(q--){
                scanf("%d",&p);
                stu[p].push_back(tmp);
            }
        }
        for(int i=1;i<=k;++i){
            sort(stu[i].begin(),stu[i].end());
            int len=stu[i].size();
            printf("%d %d\n",i,len);
            for(int j=0;j<len;++j)printf("%s\n",stu[i][j].c_str());

        }
    }
}