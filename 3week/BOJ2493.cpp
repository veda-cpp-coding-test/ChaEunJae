// 백준 문제 : 탑

#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    stack<pair<int,int>> si; // {높이, 인덱스}
    si.push({100000000,0});
    for(int i=0;i<N;i++){
        int e;
        cin >> e;
        while(si.top().first < e){
            si.pop();
        }
        cout << si.top().second << " ";
        si.push({e,i+1});
    }
}