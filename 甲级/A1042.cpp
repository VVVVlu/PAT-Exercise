#include<iostream>
using namespace std;

int main(){
    int k;
    while(scanf("%d",&k)!=EOF){
        string init[60]={"","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
                         "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
                         "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
                         "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
                         "J1","J2"};
        int permutation[60];
        string tmp[60];
        int cur=1;
        for(int i=1;i<=54;++i)
            scanf("%d",&permutation[i]);
        while(k--) {
            for (int i = 1; i <= 54; ++i)
                tmp[permutation[i]] = init[i];
            cur = 2;

            k--;
            if (k >= 0) {
                for (int i = 1; i <= 54; ++i)
                    init[permutation[i]] = tmp[i];
                  cur = 1;
            } else break;
        }
        if(cur==1){
            cout<<init[1];
            for(int i=2;i<=54;++i)cout<<" "<<init[i];
            cout<<endl;
        }
        else{
            cout<<tmp[1];
            for(int i=2;i<=54;++i)cout<<" "<<tmp[i];
            cout<<endl;
        }
    }
    return 0;
}