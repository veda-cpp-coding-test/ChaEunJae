// 백준 문제 : 톱니바퀴

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> cogwheel; // 배열은 12시부터 시계방향으로, 오른쪽 톱니는 인덱스 2, 왼쪽 톱니는 6
    for(int i=0;i<4;i++){
        string str;
        cin >> str;
        vector<int> cw;
        for(int j=0;j<8;j++){
            cw.push_back(str[j]-'0');
        }
        cogwheel.push_back(cw);
    }

    int K;
    cin >> K;
    vector<pair<int,int>> step; // {시작 톱니바퀴, 회전 방향(-1 : 반시계, 1 : 시계)}
    for(int i=0;i<K;i++){
        int cn, dir;
        cin >> cn >> dir;
        step.push_back({cn,dir});
    }

    for(auto s:step){
        vector<pair<bool,int>> isRotate(4,{false,0}); // {회전 여부, 방향}
        isRotate[s.first-1] = {true,s.second};
        
        for(int i=s.first-1;i-1>=0;i--){ // 왼쪽 톱니바퀴들과 비교
            if(cogwheel[i][6] != cogwheel[i-1][2]){
                isRotate[i-1] = {true,-isRotate[i].second};
            } else {
                break;
            }
        }

        for(int i=s.first-1;i+1<4;i++){ // 오른쪽 톱니바퀴들과 비교
            if(cogwheel[i][2] != cogwheel[i+1][6]){
                isRotate[i+1] = {true,-isRotate[i].second};
            } else {
                break;
            }
        }

        for(int i=0;i<4;i++){
            if(isRotate[i].first == true){
                // 각 톱니바퀴 회전
                if(isRotate[i].second == 1){
                    // 시계 방향
                    int tmp = cogwheel[i][0];
                    for(int j=7;j>=0;j--){
                        if(j==7) cogwheel[i][0] = cogwheel[i][7];
                        else if(j==0) cogwheel[i][1] = tmp;
                        else cogwheel[i][j+1] = cogwheel[i][j];
                    }
                } else {
                    // 반시계 방향
                    int tmp = cogwheel[i][7];
                    for(int j=0;j<8;j++){
                        if(j==0) cogwheel[i][7] = cogwheel[i][0];
                        else if(j==7) cogwheel[i][6] = tmp;
                        else cogwheel[i][j-1] = cogwheel[i][j];
                    }
                }
            }
        }

        // 디버그용 출력문
        // for(int i=0;i<4;i++){
        //     for(int j=0;j<8;j++){
        //         cout << cogwheel[i][j];
        //     }
        //     cout << "\n";
        // }
    }

    int answer = 0;
    int scoreToAdd = 1;
    for(int i=0;i<4;i++){
        if(cogwheel[i][0] == 1) answer += scoreToAdd;
        scoreToAdd *= 2;
    }
    cout << answer << "\n";
}
