#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        char sign1,sign2;
        stringstream ss;
        string tmp;
        int exp;
        int pos=s.find("E");

        sign1=s[0];
        sign2=s[pos+1];
        tmp=s.substr(pos+2,s.size()-pos-2);
        ss << tmp;
        ss >> exp;


        s.erase(pos,s.size()-pos+1);
        s.erase(0,1);
        if(s=="0.0")s="0"; //0.0应输出0
        else {
            s.erase(s.begin() + 1);
            if (sign2 == '-') {
                for (int i = 0; i < exp; ++i)s = '0' + s;
                s.insert(1, ".");
            } else {
                if (s.size() - 1 < exp)//小数部分长度不够右移，补0
                    for (int i = s.size() - 1; i < exp; ++i)s = s + '0';

                else if (s.size() - 1 > exp)//右移够长，不补0
                    s.insert(exp + 1, ".");
            }
        }
        if(sign1=='-')s=sign1+s;
        cout<<s<<endl;
    }
}