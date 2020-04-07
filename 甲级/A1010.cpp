//注意
//1.最大可能进制不是36
//2.最小可能进制一定大于串中最大的数
//3.转十进制可能溢出，判断转化结果是否小于0
//4.暴力查找测试点7会超时，用二分（但题目不是要求答案不唯一时输出满足的最小进制？）
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long int ll;

string str1,str2;
int t,r;

int main(){
while(cin>>str1>>str2>>t>>r){
    ll n1=0,n2=0;
    if(t==2){//将已知进制的串固定为str1，方便转换
        string ss;
        ss=str1;
        str1=str2;
        str2=ss;
    }
       ll c=1,tmp;
        for(int i=str1.size()-1;i>=0;--i){//计算已知进制的串的十进制数
            if(isdigit(str1[i])){
                tmp=str1[i]-'0';
            }
            else tmp=str1[i]-'a'+10;
            n1+=tmp*c;
            c*=r;
        }

       // printf("n1=%lld\n",n1);
        bool flag=false;
        ll ans,low,height;//二分
        char it = *max_element(str2.begin(),str2.end());
        if(isdigit(it))low=it-'0'+1;
        else low=it-'a'+10+1;

         height = max(n1,low);
     while(low<=height){
            ans=(low+height)/2;
               c=1;
               n2=0;
        for(int i=str2.size()-1;i>=0;--i){
            if(isdigit(str2[i])){
                tmp=str2[i]-'0';
            }
            else {
                    tmp=str2[i]-'a'+10;
            }
            n2+=tmp*c;
            c*=ans;
            if(n2>n1 || n2<0){
               break;
            }
        }
         if(n2>n1 || n2<0){
              height=ans-1;
            }
        else if(n2==n1){
            flag=true;
             break;
        }
        else low=ans+1;
       }
     //  printf("n2=%lld\n",n2);

      if(flag)printf("%d\n",ans);
      else printf("Impossible\n");

}
return 0;
}
