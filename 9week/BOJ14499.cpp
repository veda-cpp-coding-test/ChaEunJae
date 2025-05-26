// 백준 문제 : 주사위 굴리기

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {0,0,-1,1}; // 동 서 북 남
int dx[4] = {1,-1,0,0};

void swap_6(vector<int> &dice,vector<int> changeStep){
    vector<int> tmp;
    for(int i=0;i<6;i++){
        tmp.push_back(dice[i]);
    }

    for(int i=0;i<6;i++){
        dice[i] = tmp[changeStep[i]];
    }

    // for(auto d:dice){
    //     cout << d << " ";
    // }
    // cout << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M,x,y,K;
    cin >> N >> M >> x >> y >> K;

    vector<vector<int>> map;
    for(int i=0;i<N;i++){
        vector<int> m;
        for(int j=0;j<M;j++){
            int e;
            cin >> e;
            m.push_back(e);
        }
        map.push_back(m);
    }

    int command[K];
    for(int i=0;i<K;i++){
        int c;
        cin >> c;
        command[i] = c; 
    }

    vector<int> dice = {0 ,0, 0, 0, 0, 0}; // 위, 북, 동, 서, 남, 아래에 있는 면의 값
    
    pair nowLocation = {x,y}; // 맵 상의 주사위의 좌표
    for(int c:command){
        
        int nxtY = nowLocation.first+dy[c-1];
        int nxtX = nowLocation.second+dx[c-1];
        if(0<=nxtY&&nxtY<N&&0<=nxtX&&nxtX<M){
            nowLocation = {nxtY, nxtX};
            // cout << nowLocation.first << "," << nowLocation.second << "\n";

            if(c == 1){
                swap_6(dice,{3,1,0,5,4,2});
            } else if(c==2){
                swap_6(dice,{2,1,5,0,4,3});
            } else if(c == 3){
                swap_6(dice,{4,0,2,3,5,1});
            } else {
                swap_6(dice,{1,5,2,3,0,4});
            }

            if(map[nowLocation.first][nowLocation.second] == 0){
                map[nowLocation.first][nowLocation.second] = dice[5];
            } else {
                dice[5] = map[nowLocation.first][nowLocation.second];
                map[nowLocation.first][nowLocation.second] = 0;
            }

            cout << dice[0] << "\n";
        }
    } 
}