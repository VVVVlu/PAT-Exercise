//用结构体存储有理数，直接计算加减乘除，再将所有有理数化简输出
//注意：1.若用字符串存储分数，分子分母可能不止一位，不可直接字符赋值 这里可以直接用%d/%d方式拿到分子分母的值
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
typedef long long int ll;

struct N{ //有理数
    ll sign;//符号
    ll z; //整数部分
    ll fz,fm; //分子、分母
}a,b,add,sub,mul,c;

ll gcd(ll a,ll b){ //找分子分母最大公因数，约分化简
    if(b==0)return a;
    else return gcd(b,a%b);
}

void simplify(N &node){ //化简有理数

    node.z=node.fz/node.fm;
    node.fz=node.fz%node.fm;
    int tmp=gcd(node.fz,node.fm);
    node.fz/=tmp;
    node.fm/=tmp;

}

void print(N node){ //输出化简的有理数
    if(node.sign==2){ //最先判断除0
        printf("Inf");
        return;
    }
    if(node.z==0 && node.fz==0){
        printf("0");
        return;
    }
    if(node.sign==-1){

        printf("(-");
        if(node.fz==0)printf("%lld",node.z);
        else{
            if(node.z>0)printf("%lld ",node.z);
            printf("%lld/%lld",node.fz,node.fm);
        }
        printf(")");
    }else {
        if(node.fz==0)printf("%lld",node.z);
        else{
            if(node.z>0)printf("%lld ",node.z);
            printf("%lld/%lld",node.fz,node.fm);
        }
    }

    return ;
}

int main(){
    ll t1,t2,t3,t4;
    while(scanf("%lld/%lld %lld/%lld",&t1,&t2,&t3,&t4)!=EOF){


        if(t1<0){ //符号
            a.sign=-1;
            a.fz=-t1;
        }
        else{
            a.sign=1;
            a.fz=t1;
        }

        if(t3<0){ //符号
            b.sign=-1;
            b.fz=-t3;
        }else {
            b.sign=1;
            b.fz=t3;
        }

        a.fm=t2;
        b.fm=t4;


       //加法
        add.fz=(a.fz*a.sign)*b.fm+(b.fz*b.sign*a.fm);
        if(add.fz<0){
            add.sign=-1;
            add.fz=-add.fz;
        }else add.sign=1;
        add.fm=a.fm*b.fm;

        //减法
        sub.fz=(a.fz*a.sign)*b.fm-(b.fz*b.sign*a.fm);
        if(sub.fz<0){
            sub.sign=-1;
            sub.fz=-sub.fz;
        }else sub.sign=1;
        sub.fm=a.fm*b.fm;

        //乘法
        mul.sign=a.sign*b.sign;
        mul.fz=a.fz*b.fz;
        mul.fm=a.fm*b.fm;

        //除法
        if(b.fz==0)c.sign=2; //除0，标记非法
        else {
            c.sign=a.sign*b.sign;
            c.fz=a.fz*b.fm;
            c.fm=a.fm*b.fz;

        }
        //化简
        simplify(a);
        simplify(b);
        simplify(add);
        simplify(sub);
        simplify(mul);
        if(c.sign!=2) simplify(c);

         //输出
        for(int i=0;i<4;++i){
            print(a);

            if(i==0){
                printf(" + ");
            }
            else if(i==1){
                printf(" - ");
            }
            else if(i==2){
                printf(" * ");
            }else{
                printf(" / ");
            }

            print(b);

            printf(" = ");

            if(i==0){
                print(add);

            }
            else if(i==1){
                print(sub);

            }
            else if(i==2){
                print(mul);

            }else{
                print(c);
                break;
            }
            printf("\n");

        }

    }
    return 0;

}
