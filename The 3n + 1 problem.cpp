// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>//swap
//使用到swap、max、遞迴
using namespace std;

int themax(int x,int nowtime){
    ++nowtime;
    if(x == 1){
        return nowtime;
    }
    else{
        if(x % 2 == 0){
            x /= 2;
        }
        else{
           x = x*3 + 1;
        }
        return themax(x,nowtime);   //注意，遞迴也要前面用return
    }
}

int main(){
    int i,j;
    while(cin >> i >> j){ //無輸入較停止
         cout << i <<" " << j << " ";
        if(i > j){      //因為下面用for，所以若前面大於後面先交換
            swap(i,j);
        }

        int nowmax = 0;     //存目前最大
        for(int l = i;l <=j;l++){
            int nowtime = 0;
            nowtime = themax(l,nowtime);//該數cycle次數
            nowmax = max(nowmax,nowtime);//check最大
            
        }
        cout << nowmax << "\n";
    }
}