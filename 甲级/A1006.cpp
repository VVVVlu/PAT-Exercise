#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct S{
    string ID;
    string in,out;
};

bool cmpIn(const S &a,const S &b){return a.in<b.in;}
bool cmpOut(const S &a,const S &b){return a.out>b.out;}


int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        vector<S> stu;
         S tmp;
        for(int i=0;i<m;++i){
            cin>>tmp.ID>>tmp.in>>tmp.out;
            stu.push_back(tmp);
        }
        string res1,res2;
        sort(stu.begin(),stu.end(),cmpIn);
        res1=stu[0].ID;
        sort(stu.begin(),stu.end(),cmpOut);
        res2=stu[0].ID;
        printf("%s %s\n",res1.c_str(),res2.c_str());
    }
    return 0;
}