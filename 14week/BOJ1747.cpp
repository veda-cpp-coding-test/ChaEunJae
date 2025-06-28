// 백준 문제 : 소수&팰린드롬

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N;
    cin >> N;
    int nInt = stoi(N);

    while(true){
        // 팰린드롬 판단
        int start = 0;
        int end = N.size()-1;
        bool isPal = true;
        while(start <= end){
            if(N[start] != N[end]){
                isPal = false;
                break;
            }

            start++;
            end--;
        }


        // 소수 판단
        if(isPal == true){
            // cout << nInt << " 팰린드롬!\n";
            bool isPrime = true;
            for(int i=2;i<nInt;i++){
                if(nInt % i == 0){
                    isPrime = false;
                    break;
                }
            }
            if(nInt == 1) isPrime = false;
            if(isPrime == true){
                // cout << "소수!\n";
                cout << nInt << "\n";
                return 0;
            }
        } 

        // 다음 반복을 위한 증가 부분
        nInt++;
        N = to_string(nInt);
    }
}