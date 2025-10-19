//學到map
//內部可自行sort
#include <iostream>
#include<string>
#include <algorithm>

using namespace std;

int main(){
    int arry[26] = {0},
    arso[26] = {0};
    int t;
    cin >> t;
    getchar();
    while(t--){
        string str;
        getline(cin , str);
        for(int i = 0; i < str.length();++i){
            if(str[i]>='A' && str[i]<='Z'){
                arry[str[i] - 'A'] ++ ;
                arso[str[i] - 'A'] ++ ;
            }
            else if(str[i]>='a' && str[i]<='z'){
                arry[str[i] - 'a'] ++ ;
                arso[str[i] - 'a'] ++ ;
            }
        }
    }
    
    sort(arso,arso+26); //arso用來排列大小
    for(int i = 25;i>=0;--i){
        if(arso[i] != 0){
            for(int j=0;j<26;++j){//從最前面開始找輸出就會是由A-Z的順序
                if(arso[i] == arry[j]){
                    cout << (char)(j+'A') <<" "<< arry[j]<<"\n";
                    arry[j] = 0;//代表已經沒了
                    break;
                }
            }
        }
    }
}
