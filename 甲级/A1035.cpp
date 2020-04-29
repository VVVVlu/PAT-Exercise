#include<iostream>
#include<string>
using namespace std;
const int N =1e3+10;

struct P{
    string name,pwd;
}user[N];

bool isModify(string &a){
    int len=a.size();
    bool flag=false;
    for(int i=0;i<len;++i){
        switch(a[i]){
            case '1':
                a[i]='@';
                flag=true;
                break;
            case '0':
                a[i]='%';
                flag=true;
                break;
            case 'l':
                a[i]='L';
                flag=true;
                break;
            case 'O':
                a[i]='o';
                flag=true;
                break;
            default:
                break;
        }
    }
    return flag;
}

int main(){
    int n;
    P tmp;
    while(scanf("%d",&n)!=EOF){
        int size=0;
        for(int i=0;i<n;++i) {
            cin >> tmp.name >> tmp.pwd;
            if (isModify(tmp.pwd))user[size++] = tmp;
        }
        if(size==0) {
            if(n>1) printf("There are %d accounts and no account is modified\n", n);
            else printf("There is 1 account and no account is modified\n");//注意当没有需要修改的密码时，才考虑n的个数然后做不同输出
        }
        else {
            printf("%d\n",size);
            for(int i=0;i<size;++i){
                printf("%s %s\n",user[i].name.c_str(),user[i].pwd.c_str());
            }

        }
    }
    return 0;
}