#include<iostream>
#include<string>
using namespace std;

int num[15];

int main(){
    string str;
    while(cin>>str){
        for(int i=0;i<10;++i)num[i]=0;
        int len=str.size();
        for(int i=0;i<len;++i){
            ++num[str[i]-'0'];
        }
        for(int i=0;i<10;++i)
            if(num[i]>0)printf("%d:%d\n",i,num[i]);
    }
    return 0;

}