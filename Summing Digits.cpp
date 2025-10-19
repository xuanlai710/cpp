
#include <iostream>

using namespace std;
int main(){
    int t;
    while (true)
    {

        cin >> t;
        if(t == 0)  break;
        int x =0;
        while(t > 9){
            while(t > 0){
                //把她所有的數加進去
                x = x + (t%10);//數值最尾巴
                t /= 10;
            }
            t = x;
            x = 0;
        }
        cout << t << endl;
    }
}