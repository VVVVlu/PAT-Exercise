//考察STL中set 利用set的自动去重
//方案一：对所查询的两个集合，用一个新的set装入二者的元素，利用set自动去重得到两个集合无重复元素的元素个数，最后一个测试点会超时
//方案二：遍历查询的其中一个集合，在另一个集合中查找当前元素知否存在，计算出二者共有的元素的个数。
#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int m,tmp;
        set<int> s[55];
       for(int i=1;i<=n;++i){
           cin>>m;
           for(int j=0;j<m;++j){
               scanf("%d",&tmp);
               s[i].insert(tmp);
           }
       }
//方案二
       int k,q1,q2,nc=0,nt=0;
       scanf("%d",&k);
       for(int i=0;i<k;++i){
           nc=0;nt=0;
           scanf("%d %d",&q1,&q2);
           for(set<int>::iterator it=s[q1].begin();it!=s[q1].end();++it){
               if(s[q2].find(*it)!=s[q2].end())nc++;
           }
           nt=s[q1].size()+s[q2].size()-nc;
           printf("%.1lf%%\n",(double)(nc)/(double)nt*100); //printf打百分号用%转义

       }
       
//方案一

//       int k,q1,q2,cnt1,cnt2,cnt3;
//       scanf("%d",&k);
//       for(int i=0;i<k;++i){
//           set <int> sum;
//           scanf("%d %d",&q1,&q2);
//           cnt1=s[q1].size();
//           cnt2=s[q2].size();
//           for(set<int>::iterator it=s[q1].begin();it!=s[q1].end();++it)sum.insert(*it);
//           for(set<int>::iterator it=s[q2].begin();it!=s[q2].end();++it)sum.insert(*it);
//           cnt3=sum.size();
//
//
//           printf("%.1lf%%\n",(double)(cnt1+cnt2-cnt3)/(double)cnt3*100);
//       }

    }
    return 0;
}