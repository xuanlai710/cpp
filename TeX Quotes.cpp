#include<iostream>
#include<string>
//使用getline(cin,要輸入進的)
using namespace std;

int main(){
    string str;
    int time = 1;
    while(getline(cin,str)){ //getline才是斷句在\n的人(記得中間要打cin)
        for(int i = 0 ;i < str.length();++i){//<就好，他從0開始
            if(str[i] == '"'){
                if(time == 1){
                    cout << "``";
                    ++time;
                }
                else{
                    cout << "''";
                    time = 1;
                }
            }
            else    cout << str[i];
        }
        cout << "\n";
    }
    
}