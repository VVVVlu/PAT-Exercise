/*注意点：
 * 1.星期是第一对相同大写英文字母，范围A-G的才算，不是A-Z
 * 2.钟头在判断星期后才可判断，而不是从头开始数的第二对相同字符。且是0-9和A-N（a-n也不行）
 * 3.打印前导零 %02d  （2是宽度，表示两位数字，不够左补0）
 * */
#include<iostream>
#include<string>
using namespace std;

string day[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
string curDay;
int curHour,curMin;
int main(){
    string s1,s2,s3,s4;
    while(cin>>s1>>s2>>s3>>s4){
        int len1=s1.size(),len2=s2.size(),len3=s3.size(),len4=s4.size();
        int cnt=0;
        int flag=0;
        for(int i=0; i<len1 && i<len2;  ++i){
            if(s1[i]==s2[i]){
                if(flag==0){
                    if(s1[i]>='A' && s1[i]<='G') { //判断条件A-Z有测试点过不了
                        curDay=day[s1[i]-'A'];
                        flag=1;
                    }
                }
                else {
                    if(s1[i]>='0' && s1[i]<='9'){
                        curHour=s1[i]-'0';
                        break;
                    }
                    else if(s1[i]>='A' && s1[i]<='N'){
                        curHour=s1[i]-'A'+10;
                        break;
                    }

                }
            }
        }

        for(int i=0; i<len3 && i<len4; ++i){
            if(s3[i]==s4[i] && ((s3[i]>='a' &&s3[i]<='z' )|| (s3[i]>='A' && s3[i]<='Z')) )curMin=i;
        }

        cout<<curDay;
        printf(" %02d:%02d",curHour,curMin);
    }
    return 0;
}