#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;



int main(){
    string str;
    while(getline(cin,str)){
        map<string,int> cnt;
        string ans=" ";
        int times=-1;
        int len=str.size();
        string tmp;
       for(int i=0;i<len;++i){
           if(isdigit(str[i]) ||  isalpha(str[i])){
               tmp+=tolower(str[i]);
           }
           else {
               cnt[tmp]++;
               if(cnt[tmp]>times ||(cnt[tmp]==times && tmp<ans) ){
                   times=cnt[tmp];
                   ans=tmp;
               }
               tmp.clear();
               while(!isdigit(str[i]) && !isalpha(str[i]))++i;
               i--;
           }
       }
       if(times==-1){  //当只有一个单词的时候，答案为该单词且数量为1
           times=1;
           ans=tmp;
       }

       printf("%s %d\n",ans.c_str(),times);
    }
    return 0;
}