#include<iostream>
#include<vector>
using namespace std;

int main(){
 vector <int> v;
 int tmp,flag=0;
 while(scanf("%d",&tmp)!=EOF){
     v.push_back(tmp);
 }
    if(v.size()==2  && v[1]==0)printf("0 0"); //导数为零多项式的，均输出“0 0 ”
    else  for(int i=1; i<v.size(); i+=2){
          if(v[i]==0)break;
          if(flag==0){
          printf("%d %d",v[i-1]*v[i],v[i]-1);
          flag=1;
       }
         else {
          printf(" %d %d",v[i-1]*v[i],v[i]-1);
 }
    }
 printf("\n");
 return 0;

}