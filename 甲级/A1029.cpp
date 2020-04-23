//对两个数组从头开始依次比较，按照“将两条链表插成一条链表头插法”的思想，得到中位数
//注意：1.就下标来看，若两个数组长度分别为a,b 则中位数为两个数组非递减排序的第（a+b+1）/2个
//     2.注意对两个数组末尾插上一个无穷大数，不然会出错
#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
const int INF =0x3f3f3f3f;

int main(){
    vector<ll> str1,str2;
    int a=0,b=0;
    ll tmp;
    scanf("%d",&a);
    for(int i=0;i<a;++i){
            scanf("%lld",&tmp);
            str1.push_back(tmp);
    }
     str1.push_back(INF);
    scanf("%d",&b);
    for(int i=0;i<b;++i){
        scanf("%lld",&tmp);
        str2.push_back(tmp);
    }
     str2.push_back(INF);
    int mid=(a+b+1)/2,len=0,i=0,j=0;
    ll cur;

    while(len<mid){
        if(str1[i]>str2[j]){
            cur=str2[j];
            j++;
        }
        else {
          cur=str1[i];
            i++;
        }
        len++;
    }

    printf("%lld\n",cur);
    return 0;
}
