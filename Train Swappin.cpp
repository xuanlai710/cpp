#include<iostream>
#include<algorithm>
//14:12 min
//bubble sort
using namespace std;

int main(){
    int num;
    cin >> num;
    while(num--){
        int trainnum,train[51];
        cin >> trainnum;
        for(int i = 0; i < trainnum;++i){
            cin >>train[i];
        }

        //sort次數//bubblesort
        int swtime = 0;
        for(int i = trainnum-1;i >=0;--i){
            for(int j = 0;j < i;++j){
                if(train[j] > train[j+1]){ 
                    swap(train[j],train[j+1]);
                    ++swtime;
                }
            }
        }

        cout <<"Optimal train swapping takes " <<swtime <<" swaps.\n";
    }
}