#include<iostream>
#include<string>
using namespace std;

int main(){
string s1,s2;
while(cin>>s1>>s2){
    int cnt=0; //缺少的珠子数
    int len=s2.size();
    for(int i=0;i<len;++i){
        if(s1.find(s2[i])!=string::npos){
                s1.erase(s1.find(s2[i]),1);
        }
        else cnt++;
    }
    if(cnt==0){ //不缺少珠子
        printf("Yes %d\n",s1.size());
    }
    else printf("No %d\n",cnt);
}
return 0;
}
