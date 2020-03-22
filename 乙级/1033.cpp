
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1="",s2="";
    while(getline(cin,s1)){
        getline(cin,s2);
        if(s1.size()==0)cout<<s2<<endl; //没有坏键
        else{
            string res="",tmp="";
            for(int i=0;i<s2.size();++i){
                if(s2[i]>='a' && s2[i]<='z')tmp=s2[i]-'a'+'A';  //对小写字母，应检查是否记录了对应的大写字母
                else tmp=s2[i];
                if(s1.find(tmp)==string::npos) {
                    if (s2[i] >= 'A' && s2[i] <= 'Z' && s1.find("+")!=string::npos)continue ;//检查上档键
                    else res=res+s2[i];
                }

            }
            cout<<res<<endl;
        }
    }
    return 0;
}