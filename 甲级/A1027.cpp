#include<iostream>
using namespace std;

char arr[]={"0123456789ABC"};
void trans(int a,char str[]){
    str[0]='0';
    str[1]='0';
    str[2]='\0';
    int i=1;
    do{
        str[i--]=arr[a%13];
        a/=13;
    }while(a!=0);
   return ;
}

int main(){
  int a,b,c;
  while(scanf("%d %d %d",&a,&b,&c)!=EOF){
    char t1[5],t2[5],t3[5];
    trans(a,t1);
    trans(b,t2);
    trans(c,t3);
    printf("#%s%s%s\n",t1,t2,t3);
  }
  return 0;
}

