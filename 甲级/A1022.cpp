#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;


struct B{
    string title,author,keywords,publisher,year;
};


int main(){
    int n,M;
    while(scanf("%d",&n)!=EOF){
        map<string,B> m;
        B tmp;
        string str;
        char flag;
        getchar();
        for(int i=0;i<n;++i){
            
            getline(cin,str);
            getline(cin,tmp.title);
            getline(cin,tmp.author);
            getline(cin,tmp.keywords);
            getline(cin,tmp.publisher);
            getline(cin,tmp.year);
            m[str]=tmp;
        }
        scanf("%d",&M);
        getchar();
        for(int i=0;i<M;++i){
            getline(cin,str);
            printf("%s\n",str.c_str());
            flag=str[0];
            str.erase(0,str.find(' ')+1);
            bool book=0;
            switch(flag){
                case '1':
                    for(map<string,B>::iterator it=m.begin();it!=m.end();it++){
                        if(it->second.title==str){
                            book=1;
                            printf("%s\n",it->first.c_str());
                        }
                    }
                    break;
                case '2':
                    for(map<string,B>::iterator it=m.begin();it!=m.end();it++){
                        if(it->second.author==str){
                            book=1;
                            printf("%s\n",it->first.c_str());
                        }
                    }
                    break;
                case '3':
                    for(map<string,B>::iterator it=m.begin();it!=m.end();it++){
                        if(it->second.keywords.find(str)!=string::npos){
                            book=1;
                            printf("%s\n",it->first.c_str());
                        }
                    }
                    break;
                case '4':
                    for(map<string,B>::iterator it=m.begin();it!=m.end();it++){
                        if(it->second.publisher==str){
                            book=1;
                            printf("%s\n",it->first.c_str());
                        }
                    }
                    break;

                case '5':
                    for(map<string,B>::iterator it=m.begin();it!=m.end();it++){
                        if(it->second.year==str){
                            book=1;
                            printf("%s\n",it->first.c_str());
                        }
                    }
                    break;
            }
            if(!book)printf("Not Found\n");
        }
    }

    return 0;

}
