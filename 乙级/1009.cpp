#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1;
    while(getline(cin,s1)) {
        string s2;
        s1 += ' ';//末尾加空格，以空格判断作为单词结束的判断
        int pos = 0, start = 0;
        int len = s1.size();
        while (pos < len-1) {
            pos = s1.find(' ', start);
            s2 = s1.substr(start, pos - start)+' '+ s2;
            start = pos + 1;

        }
        s2.pop_back();//去掉末尾空格
        cout<<s2<<endl;

    }
    return 0;

}



