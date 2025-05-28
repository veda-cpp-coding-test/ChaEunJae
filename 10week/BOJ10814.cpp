// 백준 문제 : 나이순 정렬

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool Compare(pair<int,string> a, pair<int,string> b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int,string>> users;
    for(int i=0;i<N;i++){
        int age;
        string name;
        cin >> age >> name;

        users.push_back({age,name});
    }

    stable_sort(users.begin(),users.end(),Compare); // stable_sort는 정렬에 참여하지 않은 요소들의 원래 위치 유지 보장
    for(auto u:users){
        cout << u.first << " " << u.second << "\n";
    }
}