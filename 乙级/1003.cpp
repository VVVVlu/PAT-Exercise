/*****P左边A的个数 * PT中间A的个数 == T右边A的个数 ****/
#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0; i<n; ++i){
            string str;
            string s1,s2,s3;
            cin>>str;
            int len=str.size();
            int flag1=0,flag2=0,flag3=0,flag4=0;
            for(int i=0; i<len; ++i){  //判断是否有且仅有一个P、T和A，且其余是A
                if(str[i]=='P' && flag1==0)flag1=1;
                else if(str[i]=='T' && flag2==0)flag2=1;
                else if(str[i]=='A' && flag3==0)flag3=1;
                else if(str[i]!='A'){
                    flag4=1;
                    break;
                }

            }
            if(flag1!=1 || flag2!=1 || flag3!=1)printf("NO\n");
            else if(flag4==0) {  //分割子串
                int pos1 = str.find('P');
                int pos2 = str.find('T');
                s1 = str.substr(0, pos1);
                s2 = str.substr(pos1 + 1, pos2 - pos1 - 1);
                s3 = str.substr(pos2 + 1, str.size() - pos2 - 1);
                if(s2.size()*s1.size()==s3.size() && s2.size()!=0)printf("YES\n"); 
                else printf("NO\n");
            }
        }
    }
    return 0;
}
