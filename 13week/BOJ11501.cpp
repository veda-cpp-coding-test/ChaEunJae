// 백준 문제 : 주식

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int N;
        cin >> N;

        vector<int> vi; // c++ 표준에서는 원래 가변 길이 배열을 허락해주지 않음. 전역변수로 배열의 크기를 미리 지정해주지않는 케이스의 경우 vector를 쓰는 것이 표준. 하지만 가변 길이 배열이 생성 시간복잡도 측면에서 더 유리
        for(int i=0;i<N;i++){
            int price;
            cin >> price;
            vi.push_back(price);
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