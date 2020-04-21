//自己的做法：现将电话记录存入对应人名的map下，在排序判断前后是否是有效的通话记录。之前考虑不周，没考虑一个人存在所有通话记录都无效的情况。
//柳婼做法可借鉴：直接按名字和通话时间排序，然后判断前后两个通话记录是否属于同一人且是否有效，再加入该人名对应的map下，这样提前丢掉所有无效通话，遍历时不用再考虑。
//注意：1.所有通话记录都是某单月内的。
//     2.日期问题归结到一个起点，利用差值计算
//     3.按自己的做法，注意打印的判断


#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


struct R{
  int month,day,hour,minn;
  int time;
  int state;
};

map<string,vector<R> > customer;
int arr[30],n;
bool cmp(const R &a,const R &b){
return a.time<b.time;

}
double cal(const R &a){
    double res=a.minn*arr[a.hour]+a.day*60*arr[24];
    for(int i=0;i<a.hour;++i)res+=arr[i]*60;
    return res/100;
}
int main(){
    arr[24]=0;
    for(int i=0;i<24;++i){
            scanf("%d",&arr[i]);
            arr[24]+=arr[i];
    }

    scanf("%d",&n);
    string people,t;
    R tmp;
    for(int i=0;i<n;++i){
        cin>>people;
        scanf("%d:%d:%d:%d",&tmp.month,&tmp.day,&tmp.hour,&tmp.minn);
        tmp.time=tmp.day*24*60+tmp.hour*60+tmp.minn;
        cin>>t;
        if(t=="on-line")tmp.state=1;
        else tmp.state=0;
        customer[people].push_back(tmp);
    }
    for(map<string,vector<R> >::iterator it=customer.begin();it!=customer.end();++it){
            vector<R> a=it->second;
            double totalAmount=0.0;
        sort(a.begin(),a.end(),cmp);
          bool first=true;
        for(int i=1;i<a.size();i++){
            if(a[i-1].state==1 && a[i].state==0){
                    if(first){
                        first=false;
                            printf("%s %02d\n",it->first.c_str(),it->second[0].month);//不能提前打印，有有效通话记录的人才打印
                    }
               printf("%02d:%02d:%02d %02d:%02d:%02d",a[i-1].day,a[i-1].hour,a[i-1].minn,a[i].day,a[i].hour,a[i].minn);
                int  totalTime=a[i].time-a[i-1].time;
                 double charge=cal(a[i])-cal(a[i-1]);
                printf(" %d $%.2f\n",totalTime,charge);
                totalAmount+=charge;
                 i++;
            }
        }
        if(totalAmount!=0)//有有效通话记录的人才打印
        printf("Total amount: $%.2f\n",totalAmount);
    }
    return 0;

}
