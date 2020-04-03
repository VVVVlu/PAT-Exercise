#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string num[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string str,str2;
    while(cin>>str){
        int tmp=0,len=str.size();
        for(int i=0;i<len;++i)tmp+=(str[i]-'0');

        stringstream ss;
         ss << tmp ;
         ss >> str2;

         for(int i=0;i<str2.size();++i){
             if(i==0)printf("%s",num[str2[i]-'0'].c_str());
             else printf(" %s",num[str2[i]-'0'].c_str());
         }

    }
    return 0;
}