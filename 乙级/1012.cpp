#include<iostream>
#include<cmath>
using namespace std;

double myRound(double d, int n){ //d 4舍5入小数点后n位
    d=d*pow(10,n);
    d+0.5;
    d=d/pow(10,n);
    return  d;
}

int main(){
    int n,tmp;
    while(scanf("%d",&n)!=EOF){
        int a0=0,a1=0,a2=0,a3=0,a4=0;//5类
        int sign=1,cnt=0,flag=0;
        for(int i=0; i<n; ++i){
            scanf("%d",&tmp);
            switch(tmp%5){
                case 0:    //能被 5 整除的数字中所有偶数的和
                    if(tmp%2==0)a0+=tmp;
                    break;
                case 1:    //被 5 除后余 1 的数字按给出顺序进行交错求和
                   flag=1;  //和可能为0，与 "不存在" 区分
                   a1+=sign*tmp;
                   if(sign==1)sign=-1;
                   else sign=1;
                   break;
                case 2:   //被 5 除后余 2 的数字的个数
                    a2++;
                    break;
                case 3:   //被 5 除后余 3 的数字和
                    a3+=tmp;
                    cnt++;
                    break;
                case 4:   //被 5 除后余 4 的数字中最大数字
                    if(tmp>a4)a4=tmp;
                    break;

            }
        }
        if(a0==0)printf("N ");
        else printf("%d ",a0);
        if(a1==0 && flag==0)printf("N ");
        else printf("%d ",a1);
        if(a2==0)printf("N ");
        else printf("%d ",a2);
        if(a3==0)printf("N ");
        else printf("%.1lf ",myRound( (double)a3/(double)cnt , 1) );
        if(a4==0)printf("N");
        else printf("%d",a4);
        printf("\n");
    }
    return 0;
}
