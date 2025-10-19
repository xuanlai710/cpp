#include <iostream>

using namespace std;

// int fin(int x){
//     if(x == 1) return 1;
//     else if(x == 0) return 0;
//     else{
//         return fin(x)+fin(x-2);
//     }
// }

int main(){
    int t;
    cin >> t;
    //數字最大到100000000，45的費式數列就夠了
    int fibon[45] = {0,1,1,2,3,5,8,13,21,34,55};
    int maxnum = 10;
    while(t--){
        int number;
        cin >> number;

        //找大於輸入的費氏數列
        for(int i=2;fibon[i] != 0;++i){
            if(fibon[i] > number){
                maxnum = i;
                break;
            }
            //如果現在存的不夠
            //往後找直到找到大於輸入的(其他存起來)
            if(fibon[i+1] == 0){
                do{
                    i += 1;
                    fibon[i] = fibon[i-1]+fibon[i-2];
                }while(fibon[i] < number);  
                maxnum = i;  
                break;
            }
        }
        //開始輸出(因為找到的是大於輸入的，所以他前一個是所有小於number中最大的一個，最小是2的費氏)
        cout << number << " = ";
        for(int i = maxnum-1;i >= 2; --i){
            if(number >= fibon[i]){
                number -= fibon[i];
                cout << "1";
            }
            else{
                cout << "0";
            }
        }
        cout << " (fib)\n";
    }
}