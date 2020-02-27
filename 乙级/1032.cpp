#include<iostream>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int label,maxScore=-1;
        int arr[n+5];
        int a,b;
        for(int i=0;i<n;++i)arr[i]=0;
        for(int i=0;i<n;++i){
            scanf("%d %d",&a,&b);
            arr[a]+=b;
            if(arr[a]>maxScore){
                label=a;
                maxScore=arr[a];
            }
        }
        printf("%d %d\n",label,maxScore);
    }
    return 0;
}