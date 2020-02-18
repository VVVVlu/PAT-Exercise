#include<iostream>
#include<algorithm>
using namespace std;



int main(){
    int arr[55];
    int cnt,size=0;
    for(int i=0;i<10;++i){ 
        scanf("%d",&cnt);
        while(cnt!=0){
            arr[size++]=i;
            --cnt;
        }
    }
    sort(arr,arr+size);
    int start=0,tmp;
    while(arr[start]==0)++start;  //找到第一个不为0的数字，作为首位
    tmp=arr[0];
    arr[0]=arr[start];
    arr[start]=tmp;
     for(int i=0; i<size; ++i)
       printf("%d",arr[i]);
     printf("\n");
    return 0;
}