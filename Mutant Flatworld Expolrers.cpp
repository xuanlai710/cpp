#include<iostream>

using namespace std;

int main(){
    int x ,y;
    cin >> x >> y;

    int nx, ny;
    char direction;
    bool ary[51][51] = {0};
    while(cin >> nx >> ny >> direction){
        string work;
        cin >> work;

        bool End = true;
        for(int i = 0;i < work.length();i++){
            // 面向北方:
                //     R: E
                //     L: W
                //     F: y++
            // 南方:
                //     R: W
                //     L: E
                //     F: y--
            // 東方:
                //     R: S
                //     L: W
                //     F: x++
            // 西方:
                    //     R: N
                    //     L: S
                    //     F: x--
            if(work[i] == 'R'){
                if(direction == 'N')
                    direction = 'E';
                else if(direction == 'S')
                    direction = 'W';
                else if(direction == 'E')
                    direction = 'S';
                else
                    direction = 'N';
            }
            else if(work[i] == 'L'){
                if(direction == 'N')
                    direction = 'W';
                else if(direction == 'S')
                    direction = 'E';
                else if(direction == 'E')
                    direction = 'N';
                else
                    direction = 'S';
            }
            else{
                int cx = nx,cy = ny; //c是用來確認下一步的位置
                //所以要先設為先走之前的位置(雖然會有一軸沒加減，但可能要確認之前有沒有人在這裡掉下去，所以還是要保留)
                if(direction == 'N')
                    cy = ny+1;
                else if(direction == 'S')
                    cy = ny-1;
                else if(direction == 'E')
                    cx = nx+1;
                else
                    cx = nx-1;
                
                //確認有無跑出
                // 掉下去的機器人會留下「標記 ( scent ) 」，提醒以後的機器人，避免他們從同一個地方掉下去。
                // 掉下去的機器人會把標記，留在他掉落之前所在的最後一個坐標點。
                // 所以對於以後的機器人，當他正位在有標記的地方時，這個機器人就會忽略會讓他掉下去的指令。
                if(cy > y ||cy < 0|| cx > x||cx <0){
                    if(ary[nx][ny] != 1){
                        cout << nx << " " <<  ny << " " << direction << " LOST" <<"\n";
                        ary[nx][ny] = 1;
                        End = false;
                        break;
                    }
                    //若是1就是之前債這裡有人在這裡掉下去過，無視現在讓他掉下去資訊nx,ny還是原來的
                }
                else{
                    nx = cx;
                    ny = cy;
                }
            }     
        }
        if(End)
            cout << nx << " " <<  ny << " " << direction << "\n";
    }

}