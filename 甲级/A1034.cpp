#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int n,k,cnt,total;
string header;
map<string,vector<string> > g;
map<string,int> r;
map<string,int> v;
map<string,int>gang;

void DFS(string a){
    v[a]=1;
    cnt++;
    total=total+r[a];
    for(int i=0;i<g[a].size();++i){
            string nbr=g[a][i];
    if(v[nbr]==0){
        if(r[nbr]>r[header])header=nbr;
            DFS(nbr);
    }
}
    return ;
}

int main(){
while(scanf("%d %d",&n,&k)!=EOF){
        g.erase(g.begin(),g.end());
         r.erase(r.begin(),r.end());
         v.erase(v.begin(),v.end());
          gang.erase(gang.begin(),gang.end());
         cnt=0;
    string a,b;
    int tmp;
    for(int i=0;i<n;++i){
        cin>>a>>b>>tmp;
        g[a].push_back(b);
        g[b].push_back(a);
        v[a]=0;v[b]=0;
        if(r.find(a)==r.end())r[a]=0;
        if(r.find(b)==r.end())r[b]=0;
        r[a]=r[a]+tmp;
        r[b]=r[b]+tmp;
    }

    for(map<string,int>::iterator it=v.begin();it!=v.end();++it){
        if(it->second==0){
                header=it->first;
                cnt=0;
                total=0;
                DFS(it->first);
    }
     if(cnt>2 && (total/2)>k){
     gang[header]=cnt;
     }
}
printf("%d\n",gang.size());
for(map<string,int>::iterator it=gang.begin();it!=gang.end();++it)
    printf("%s %d\n",it->first.c_str(),it->second);
}
return 0;
}
