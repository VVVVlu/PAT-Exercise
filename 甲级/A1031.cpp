#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        int len=str.size()+2;
        int x=len/3+len%3;
        int y=len/3,space=x-2;
        for(int i=0;i<y-1;++i){
            char t1=str[i],t2=str[len-3-i];
            printf("%c",t1);
            int t3 = 0;
            while(t3<space){
                printf(" ");
                t3++;
            }
            printf("%c\n",t2);
        }
        printf("%s\n",str.substr(y-1,x).c_str());

    }
    return 0;
}