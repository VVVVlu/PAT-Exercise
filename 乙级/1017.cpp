
#include<iostream>
#include<string>
using namespace std;

int main(){
    string a,q;// 被除数、商
    int b,r;//除数、余数
    while(cin>>a>>b) {
        if (b != 0) {
            int len = a.size();
            int t = 0;
            char c;
            for (int i = 0; i < len; ++i) {
                t = t * 10 + a[i] - '0';
                c = (t / b) + '0';
                q += c;
                t = t % b;
            }
            r = t;
            if (q[0] == '0' && q.size()>1)q.erase(0, 1);  //被除数可能为0
            cout << q << " " << r << endl;
        }
    }
    return 0;
}