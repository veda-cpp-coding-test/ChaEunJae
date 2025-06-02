// 백준 문제 : 먹을 것인가 먹힐 것인가

#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        int N,M;
        cin >> N >> M;
        vector<int> A;
        vector<int> B;

        for(int j=0;j<N;j++){
            int e;
            cin >> e;
            A.push_back(e);
        }
        for(int j=0;j<M;j++){
            int e;
            cin >> e;
            B.push_back(e);
        }

        int count = 0;
        for(int j=0;j<N;j++){
            for(int z=0;z<M;z++){
                if(A[j] > B[z]){
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
}