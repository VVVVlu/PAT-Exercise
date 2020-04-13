//通过统计初始串和结果串中各数字的个数来判断是否为置换。
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    string str;
    while(cin>>str){
        string res="";
        int c=0,t;
        int cntstr[15],cntres[15];
        char tmp;
        memset(cntstr,0,sizeof(cntstr));
        memset(cntres,0,sizeof(cntres));
        for(int i=str.size()-1;i>=0;--i){
            cntstr[str[i]-'0']++;
            t=c+2*(str[i]-'0');
            c=t/10;
            tmp=(t%10)+'0';
            cntres[t%10]++;
            res=tmp+res;
        }
        if(c!=0){
            tmp=c+'0';
            res=tmp+res;
        }
        bool flag=true;
        if(res.size()!=str.size())flag=false;
        else {
            for(int i=0;i<10;++i){
                if(cntstr[i]!=cntres[i]){
                    flag=false;
                    break;
                }
            }
        }
        if(!flag){
            printf("No\n%s",res.c_str());
        }
        else {
            printf("Yes\n%s",res.c_str());
        }
    }
    return 0;

}