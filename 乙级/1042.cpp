#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int alpha[30];

int main(){

string str;
while(getline(cin,str)){
    for(int i=0;i<30;++i)alpha[i]=0;
    int len=str.size();
    for(int i=0;i<len;++i){
        if(isalpha(str[i])){
            if(str[i]>='A' && str[i]<='Z')alpha[str[i]-'A']++;
            else alpha[str[i]-'a']++;
        }
    }
   int maxNum=-1,maxCnt=0;
    for(int i=0;i<26;++i)
    if(alpha[i]>maxCnt){
        maxNum=i;
        maxCnt=alpha[i];
    }
    printf("%c %d\n",maxNum+'a',maxCnt);
}
return 0;
}
