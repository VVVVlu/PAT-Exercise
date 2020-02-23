#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s1,s2,s3;
    while(cin>>s1){
        while(s1.size()<4)s1='0'+s1; //给定的是正整数，不一定是4位数
      do{
          int a=0,b=0,c;
          s2=s1;
          sort(s1.begin(),s1.end(),greater<char>());
          sort(s2.begin(),s2.end());
          for(int i=0;i<4;++i){
              a=a*10+s1[i]-'0';
              b=b*10+s2[i]-'0';
          }
          c=a-b;
          s3=to_string(c);
          while(s3.size()<4)s3='0'+s3;
          cout<< s1 <<" - "<< s2 <<" = "<< s3 <<endl;
          s1=s3;
      }while(s3!="6174" && s3!="0000");
    }
    return 0;
}