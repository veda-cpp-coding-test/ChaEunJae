// 백준 문제 : 수 정렬하기 5

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    // 퀵 소트 최악 시간 복잡도 = O(NlogN) = 1000000 * 6
    sort(arr,arr+N);
    for(auto a:arr){
        cout << a << "\n";
    }
}