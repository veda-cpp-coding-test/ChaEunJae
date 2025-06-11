// 백준 문제 : 파도반 수열

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    long long p[101];
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    for(int i=6;i<=100;i++){
        p[i] = p[i-1] + p[i-5];
    }

    for(int i=0;i<T;i++){
        int N;
        cin >> N;

        cout << p[N] << "\n";
    }
}