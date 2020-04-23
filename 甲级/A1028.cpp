//使用string数组存学生信息，利用下标索引进行对应列排序。
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct S{
string msg[5];
};
int flag=-1;
vector<S> student;

bool cmp(const S &a,const S &b){
  if(a.msg[flag]!=b.msg[flag])return a.msg[flag]<b.msg[flag];
  return a.msg[1]<b.msg[1];
}

int main(){
int n;
while(scanf("%d %d",&n,&flag)!=EOF){
        student.clear();
        S tmp;
        for(int i=0;i<n;++i){
        cin>>tmp.msg[1]>>tmp.msg[2]>>tmp.msg[3];
        student.push_back(tmp);
        }
         sort(student.begin(),student.end(),cmp);
         for(int i=0;i<n;++i)printf("%s %s %s\n",student[i].msg[1].c_str(),student[i].msg[2].c_str(),student[i].msg[3].c_str());
}
return 0;
}
