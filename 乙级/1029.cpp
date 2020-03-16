//设原字符串s1，残缺字符串s2.  坏键记录字符串res
// 遍历s1，从s2第一个字符开始与s1字符比较：若s1当前字符和s2当前字符相同，s2将用下一个字符与后续s1中字符比较；若不同则说明s1当前字符是坏键，若坏键未被记录，则加入res末尾
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        string res="";
        int len=max(s1.size(),s2.size());
        int cur=0;
        char tmp;
        for(int i=0;i<len;++i){
            tmp=s1[i];
            if(s1[i]>='a'&& s1[i]<='z')tmp=tmp-'a'+'A';
            if(cur>=s2.size()){ // s2中对应字符遍历完了，若s1中还要字符，一定是坏键
                if(res.find(tmp)==string::npos)//该坏键第一次发现
                    res=res+tmp;
            }
            else {
                if(s1[i]==s2[cur])cur++;
                else {
                    if(res.find(tmp)==string::npos)//该坏键第一次发现
                        res=res+tmp;
                }
            }
        }
        printf("%s\n",res.c_str());
    }
    return 0;
}