//注意：
//1.1814年9月6日前的生日、2014年9月6日后的生日非法
//2.有效日期数可能为0，单独判断。
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N= 1e5+5;

struct People{
  char name[10];
  int year,month,day;

}people[N];

bool cmp(const People &a,const People &b){
if(a.year!=b.year)return a.year<b.year;
else if(a.month!=b.month)return a.month<b.month;
else return a.day<b.day;
}

int main(){
 int n;
 while(scanf("%d",&n)!=EOF){
        People tmp;
        int cnt=0;
   for(int i=0;i<n;++i){
    scanf("%s %d/%d/%d",tmp.name,&tmp.year,&tmp.month,&tmp.day);
     if(tmp.year>=2014 || tmp.year<=1814){
        if(tmp.year==2014){
            if(tmp.month<9 ||( (tmp.month==9) &&(tmp.day<=6)))
                              people[cnt++]=tmp;
        }
        else if(tmp.year==1814){
            if(tmp.month>9 || ((tmp.month==9)&&(tmp.day>=6)))
                people[cnt++]=tmp;
        }
        else continue;
        }
       else  people[cnt++]=tmp;
     }
  if(cnt!=0){
     sort(people,people+cnt,cmp);
     printf("%d %s %s\n",cnt,people[0].name,people[cnt-1].name);
  }
     else printf("0\n");//无有效生日
   }
   return 0;
 }

