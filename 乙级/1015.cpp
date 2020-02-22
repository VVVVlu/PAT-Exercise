#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct S{
    char id[20];
    int de,cai;
    int total;//总分
};
vector <S> s1,s2,s3,s4;//四类

bool cmp(S a,S b){
    if(a.total!=b.total)return a.total>b.total;
    else if(a.de!=b.de)return a.de>b.de;
    return strcmp(a.id,b.id)<0;
}

int main(){
    int n,l,h,m;
    S tmp;
    while(scanf("%d %d %d",&n,&l,&h)!=EOF){

        for(int i=0;i<n;++i){
            scanf("%s %d %d",tmp.id,&tmp.de,&tmp.cai);
            if(tmp.de>=l && tmp.cai>=l) {
                tmp.total = tmp.de + tmp.cai;

                if(tmp.de>=h ){
                    if(tmp.cai >=h) s1.push_back(tmp); //1
                    else s2.push_back(tmp);  //2
                }
                else if(tmp.de>=tmp.cai ) s3.push_back(tmp);//3
                else s4.push_back(tmp); //4

            }
        }
        m=s1.size()+s2.size()+s3.size()+s4.size();
        sort(s1.begin(),s1.end(),cmp);
        sort(s2.begin(),s2.end(),cmp);
        sort(s3.begin(),s3.end(),cmp);
        sort(s4.begin(),s4.end(),cmp);
        printf("%d\n",m);
        for(int i=0;i<s1.size();++i)cout<<s1[i].id<< " "<< s1[i].de<<" "<<s1[i].cai<<endl;
        for(int i=0;i<s2.size();++i)cout<<s2[i].id<< " "<< s2[i].de<<" "<<s2[i].cai<<endl;
        for(int i=0;i<s3.size();++i)cout<<s3[i].id<< " "<< s3[i].de<<" "<<s3[i].cai<<endl;
        for(int i=0;i<s4.size();++i)cout<<s4[i].id<< " "<< s4[i].de<<" "<<s4[i].cai<<endl;
    }
    return 0;

}

