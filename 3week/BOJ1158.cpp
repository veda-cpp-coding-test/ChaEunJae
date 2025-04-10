// 백준 문제 : 요세푸스 문제

#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N,K;
	cin >> N >> K;
	
	queue<int> qi;
    for(int i=1;i<=N;i++){
        qi.push(i);
    }

    int step = 0; // 사람 제거한 횟수
    cout << "<";
    while(step < N){
        int cnt = 0; // n번째 카운트
        int e;
        while(true){
            e = qi.front(); qi.pop();
            cnt++;
            if(cnt >= K){
                break; 
            } else {
                qi.push(e);
            }
        }

        step++;
        if(step >= N){
            cout << e;
        } else {
            cout << e << ", ";
        }
        
    }
    cout << ">";
    
}