//4次排序，用map存每个学号对应的最佳排名及其类型
//注意：1.排名从1开始到n 非0-n
//     2.平均值计算要四舍五入
//     3.同分的人排名相同，如1号2号3号同学数学分相同，则三位同学的数学排名均为第一
//     4.查询同学没成绩时，输出N/A
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

struct G{
    int no;
    char type;
};
struct S{
    string id;
    int source[4];
}stu[2010];
map<string,G> best;
int flag=-1,n,k;

bool cmp(const S &a,const S &b){
    return a.source[flag]>b.source[flag];
}

void rrank(char a,int f){
    flag=f;
    sort(stu+1,stu+n+1,cmp);
    int t=1;
    G tmp;
    tmp.type=a;
    for(int i=1;i<=n;++i){
        if(stu[t].source[flag]!=stu[i].source[flag]){
            t=i;
        }
        tmp.no=t;
        if(a=='A')best[stu[i].id]=tmp;
        else if(t<best[stu[i].id].no)best[stu[i].id]=tmp;
    }
}

int main(){
    while(scanf("%d %d",&n,&k)!=EOF){

       for(int i=1;i<=n;++i){
           cin>>stu[i].id>>stu[i].source[1]>>stu[i].source[2]>>stu[i].source[3];
           stu[i].source[0]=(((stu[i].source[1]+stu[i].source[2]+stu[i].source[3])*10/3)+5)/10;
       }

       char arr[]={"ACME"};
        for(int i=0;i<4;++i)rrank(arr[i],i);//按优先级排序

        string qry;
        for(int i=0;i<k;++i){
            cin>>qry;
            if(best.count(qry)>0)printf("%d %c\n",best[qry].no,best[qry].type);
            else printf("N/A\n");
        }
    }
    return 0;
}