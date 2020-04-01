#include<iostream>
#include<map>
#include<string>
using namespace std;

struct S{
    string id;
    int sit;

};

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        S tmp;
        int c;
        map<int,S> m;
        for(int i=0;i<n;++i){
           cin>>tmp.id>>c>>tmp.sit;
           m[c]=tmp;
        }
        int p;
        scanf("%d",&p);
        for(int i=0;i<p;++i){
            scanf("%d",&c);
            printf("%s %d\n",m[c].id.c_str(),m[c].sit);
        }
    }
    return 0;
}