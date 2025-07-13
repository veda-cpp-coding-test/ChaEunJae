// 백준 문제 : List of Unique Numbers

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> arr(N,0);
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    vector<bool> chk(100001,false);
    int end=0;
    long long answer = 0;
    chk[arr[0]] = true;
    for(int start=0;start<N;start++){
        while(end < N-1 && !chk[arr[end+1]]){
            // cout << start << " " << end << "\n";
            end++;
            chk[arr[end]] = true;
        }
        answer += end-start+1;
        // cout << "answer 더하기 "<<end << "," << start << "\n";
        chk[arr[start]] = false;
    }

    cout << answer << "\n";
}
