
#include <iostream>
#include<string>
#include<sstream>
using namespace std;


string cha[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{
    string n;
    while(cin>>n){
        int sum=0;
        string ssum;
        stringstream ss;
        for(int i=0;i<n.length();++i) {
            sum += n[i] - '0';
        }
        ss << sum;
        ss >> ssum;
        int len=ssum.length();
        int flag =1;
        int j;
        for(j=0;j<len;++j){
            if(flag)flag=0;
            else cout<<" ";
            cout<<cha[ssum[j]-'0'];
        }



    }
    return 0;
}

