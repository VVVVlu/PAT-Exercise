#include<iostream>
#include<string>
#include<map>
using  namespace std;

map<string,int> m;//存放各英文字母数量

int main(){
string str;
while(cin>>str){

    int len=str.size();
    string tmp;
    for(int i=0;i<len;++i){
            tmp=str[i];
        if(m.find(tmp)!= m.end()) m[tmp]++;//该字母已存在
        else m[tmp ]=1;
    }


    while(m["P"]!=0 ||m["A"]!=0 || m["T"]!=0 || m["e"]!=0 || m["s"]!=0 || m["t"]!=0)
    {
        if(m["P"]!=0){
            printf("P");
            m["P"]--;
        }
         if(m["A"]!=0){
            printf("A");
            m["A"]--;
        }
         if(m["T"]!=0){
            printf("T");
            m["T"]--;
        }
         if(m["e"]!=0){
            printf("e");
            m["e"]--;
        }
         if(m["s"]!=0){
            printf("s");
           m["s"]--;
        }
         if(m["t"]!=0){
            printf("t");
            m["t"]--;
        }
    }
    printf("\n");
}
return 0;
}
