// 백준 문제 : Puyo Puyo

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {-1, 0, 1, 0}; // 상 우 하 좌
int dx[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> field;
    for(int i=0;i<12;i++){
        vector<char> f;
        for(int j=0;j<6;j++){
            char c;
            cin >> c;
            f.push_back(c);
        }
        field.push_back(f);
    }

    int answer = 0;
    bool isChaining;
    do {
        isChaining = false;
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(field[i][j] != '.'){
                    // bfs
                    int count = 1;
                    queue<pair<int,int>> qp;
                    queue<pair<int,int>> history;
                    vector<vector<bool>> visited(12,vector<bool>(6,false));

                    qp.push({i,j});
                    history.push({i,j});
                    visited[i][j] = true;

                    while(!qp.empty()){
                        auto cur = qp.front(); qp.pop();
                        // cout << "bfs : " << cur.first << "," << cur.second << "\n";
                        for(int z=0;z<4;z++){
                            int ny = cur.first + dy[z];
                            int nx = cur.second + dx[z];
                            if(0 <= ny && ny < 12 && 0 <= nx && nx < 6 && visited[ny][nx] == false){
                                if(field[ny][nx] == field[cur.first][cur.second]){
                                    qp.push({ny,nx});
                                    history.push({ny,nx});
                                    visited[ny][nx] = true;
                                    count++;
                                }
                            }
                        }
                    }
                    if(count >= 4){
                        isChaining = true;
                        while(!history.empty()){
                            auto h = history.front(); history.pop();
                            field[h.first][h.second] = '.';
                        }

                        // field 출력
                        // for(int u=0;u<12;u++){
                        //     for(int o=0;o<6;o++){
                        //         cout << field[u][o];
                        //     }
                        //     cout << "\n";
                        // }

                    }
                    
                }
            }
        }
        // 1 연쇄 끝남
        // cout << "chain : " << answer <<"\n";
        for(int i=11;i>=0;i--){
            for(int j=0;j<6;j++){
                if(field[i][j] != '.'){
                    int ny = i;
                    do {
                        ny++; // 낙하
                    } while(ny < 12 && field[ny][j] == '.');
                    if(ny-1 != i) {
                        field[ny-1][j] = field[i][j];
                        field[i][j] = '.';
                    }
                }
            }
        }
        if(isChaining == true){
            answer++;
        }
    } while(isChaining == true);
    cout << answer << "\n";
}