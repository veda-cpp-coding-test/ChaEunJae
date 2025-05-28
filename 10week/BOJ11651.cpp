// 백준 문제 : 좌표 정렬하기 2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int,int>> locations;
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        locations.push_back({x,y});
    }

    sort(locations.begin(),locations.end(),Compare);
    for(auto l:locations){
        cout << l.first << " " << l.second << "\n";
    }
}