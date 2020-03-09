//注：按照用例，地球数字13表示火星数字为 tam ，即低位为0不输出
#include<iostream>
#include<cctype>
#include<sstream>
#include<map>
#include<string>
using namespace std;

string low[]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string higher[]={" ","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

map<string,int> m;
string tmp;


void init(){
    for(int i=0;i<13;++i){
        m[low[i]]=i;
    }
    for(int i=1;i<13;++i){
        m[higher[i]]=i;
    }
}
void transMars()
{
    stringstream ss;
    int a;
    string res;
    ss << tmp; //字符串转10进制
    ss >> a;
    if(a==0)res=low[0];//处理0
    else {
        if (a % 13 != 0)
            res = low[a % 13]; //10进制->13进制
        a /= 13;
        if (a != 0) {
            if (res.size() != 0)
                res = higher[a % 13] + " " + res;
            else res = higher[a % 13];
        }

    }

    printf("%s\n",res.c_str());
}

void transEarth(){
    int res=0;
    if(tmp.find(' ')!=string::npos) { //有两位火星数字
        string s1 = tmp.substr(0, 3);
        tmp.erase(0,4);
        res=13*m[s1]+m[tmp];
    }
    else {  //只有一位火星数字
        res=m[tmp];
        for(int i=1;i<13;++i){
            if(tmp==higher[i]){
                res=m[tmp]*13;
                break;
            }
        }

    }
    printf("%d\n",res);

}

//写法较繁琐，参考网上如下：
//void transEarth(){
//    int t1=0,t2=0;
//    string s1=tmp.substr(0,3),s2;
//    if(tmp.size()>4)s2=tmp.substr(4,3);
//    for(int j=1;j<13;++j){
//        if(s1==low[j] || s2==low[j])t2=j;
//        if(s1==higher[j])t1=j; //若高位存在，只可能是s1
//    }
//    printf("%d\n",t1*13+t2);
//
//}
//
//void transMars(){
//    stringstream ss;
//    int a;
//    string res;
//    ss << tmp; //字符串转10进制
//    ss >> a;
//    if(a/13)printf("%s",higher[a/13].c_str());//有高位则输出高位
//    if((a/13) && (a%13))printf(" ");
//    if((a%13) || a==0)printf("%s",low[a%13].c_str());
//    printf("\n");
//}

int main(){
    int n;
    init();
    while(scanf("%d",&n)!=EOF){
        getchar();
        for(int i=0;i<n;++i) {
            getline(cin,tmp);
            if (isdigit(tmp[0]))transMars();  //transform earth number to Mars's
            else transEarth();   //transform Mars number to earth's
        }
    }
    return 0;
}