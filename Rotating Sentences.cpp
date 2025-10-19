#include<iostream>
#include <vector>
#include<string>
//使用到vector
using namespace std;

int main(){
    string str;
    vector<string> v;
    int size = 0;
    while(getline(cin, str)){
        v.push_back(str);
        size = max(size,(int)str.length());//str.length是unsigned long long
    }
    for(int i =0;i < size;++i){//先從第一個位數開始輸出
        for(int j = v.size()-1;j>=0;--j){//從最後一行開始輸出
            if( v[j].length() >= i+1)
                cout << v[j][i];
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }
}