#include<iostream>
#include<map>
using namespace std;

int main(){
    string s1,s2;
    while(getline(cin,s1)){
        getline(cin,s2);
        map<char,bool> label;
        for(int i=0;i<s2.size();++i){
            label[s2[i]]=true;
        }
        string res="";
        for(int i=0;i<s1.size();++i){
            if(label.find(s1[i])==label.end())res+=s1[i];
        }
   cout<<res<<endl;
    }
    return 0;
}