// 백준 문제 : 날짜 계산

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int E,S,M;
    cin >> E >> S >> M;

    int curE = 1;
    int curS = 1;
    int curM = 1;
    int cnt = 1;
    while(!(E == curE && S == curS && M == curM)){
        curE++;
        if(curE > 15) curE = 1;
        curS++;
        if(curS > 28) curS = 1;
        curM++;
        if(curM > 19) curM = 1;
        cnt++;
    }
    cout << cnt << "\n";
}
