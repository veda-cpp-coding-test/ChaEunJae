// 백준 문제 : 에라토스테네스의 체

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,K;
    cin >> N >> K;

    bool che[N+1];
    for(int i=2;i<N+1;i++){
        che[i] = false;
    }

    int sosu = 2;
    int cnt = 1;
    int mulCnt = 1;
    while(cnt <= K)
    {
        // 지운 수인지 체크
        if(che[sosu * mulCnt] == false) {
            che[sosu * mulCnt] = true;
            // cout << sosu * mulCnt << "\n";

            mulCnt++;
            cnt++;
            if(cnt > K){
                // K번째 수 출력
                cout << sosu * (mulCnt-1) << "\n";
                return 0;
            }

            if(sosu * mulCnt > N){
                // sosu 교체
                for(int i=2;i<N+1;i++){
                    if(che[i] == false) {
                        sosu = i;
                        break;
                    }
                }
                mulCnt = 1;
            }
        } else {
            mulCnt++;

            if(sosu * mulCnt > N){
                // sosu 교체
                for(int i=2;i<N+1;i++){
                    if(che[i] == false) {
                        sosu = i;
                        break;
                    }
                }
                mulCnt = 1;
            }
        }
    }
}