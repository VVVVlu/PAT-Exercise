#include<iostream>
#include<algorithm>
using namespace std;

#define max 15

struct S{
  char name[max];
  char no[max];
  int score;
};

bool cmp(S a, S b){
    return a.score>b.score;
}

int main(){

    int n;
    while(scanf("%d",&n)!=EOF){
       S stu[n+1];
       for(int i=0;i<n;++i){
           scanf("%s %s %d",&stu[i].name,&stu[i].no,&stu[i].score);
       }

       stable_sort(stu,stu+n,cmp);

       //output
       printf("%s %s\n",stu[0].name,stu[0].no);
       printf("%s %s\n",stu[n-1].name,stu[n-1].no);

    }
    return 0;
}