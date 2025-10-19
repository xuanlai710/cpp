//輸入兩行，從最後去比對相同的英文並輸出
#include<iostream>

using namespace std;

int main(){
    string str1, str2;
    while (getline(cin,str1))
    {
        getline(cin,str2)
        int strend = str2.length();
        for(int i = str1.length()-1; i >=0 ;--i){
            for(int j = strend-1; j >=0 ;--j){
                if(str1[i] == str2[j]){
                    cout << str2[j];
                    strend = j;
                    break;
                }
            }
        }
        cout << endl;
    }
    
}