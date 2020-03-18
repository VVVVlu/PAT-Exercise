#include<iostream>
#include<vector>
#include<cctype>
#include<string>
using namespace std;

int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char m[]={'1','0','X','9','8','7','6','5','4','3','2'};

int main(){
int n;
while(scanf("%d",&n)!=EOF){
        int check;
        bool flag;
        string tmp;
        vector<string> res;
    for(int i=0;i<n;++i){
        cin>>tmp;
        check=0;
        flag=true;
        for(int j=0;j<17;++j){
            if(!isdigit(tmp[j])){ //前17位有非数字字符，不合法
                res.push_back(tmp);
                flag=false;
                break;
            }
        else   check=(check+(tmp[j]-'0')*w[j])%11; //注意tmp[j]为字符，tmp[j]-'0'得到字符对应数值
        }
        if(flag){
            if(m[check%11]!=tmp[17])res.push_back(tmp); //检查校验码
        }
    }
    if(res.size()==0)printf("All passed\n");
    else {
        for(int i=0;i<res.size();++i)printf("%s\n",res[i].c_str());
    }
}
return 0;
}
