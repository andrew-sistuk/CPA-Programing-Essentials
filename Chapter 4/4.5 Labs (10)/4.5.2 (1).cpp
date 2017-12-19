#include <string>
#include <stdlib.h>


using namespace std;

int main()
{
    string ip,mes="Correct IP;",t,f,l,allow="12347890.";
    int pre=0,now=0;
    getline(cin,ip);
    l=ip;
    for(int i=0;i<ip.length();++i){

            if(allow.find(ip[i])==string::npos){
            mes="Only digits and dots allowed;";
            break;
            }
    }
    for(int i=0; i<=3;++i){

        now+=l.find('.');
        if(i==3){
            t=ip.substr(pre);
            if(t.find('.')!=string::npos){
                mes="Too many parts;";
                break;
            }
        }
        else{
            t=ip.substr(pre,now);
            l=ip.substr(now);
        }

        pre+=now+1;
        if(t.length()>=4){
            mes="Too many characters in a part;\n";
            break;
        }
       if(atoi(t.c_str())>255){
            mes="Too big a value of a part;";
        }
    }
            cout<<mes<<endl;

    return 0;
}