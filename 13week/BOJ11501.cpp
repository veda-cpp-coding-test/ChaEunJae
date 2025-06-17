// 백준 문제 : 주식

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int N;
        cin >> N;

        int vi[N];
        for(int i=0;i<N;i++){
            cin >> vi[i];
        }

        long long answer = 0;
        int maxN = vi[N-1];
        for(int i=N-2;i>=0;i--){
            if(maxN > vi[i]) {
                answer += maxN-vi[i];
            } else {
                maxN = vi[i];
            }
        }
        cout << answer << "\n";
    }
}