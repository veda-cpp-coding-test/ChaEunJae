// 백준 문제 : 숫자 카드 2

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int Ns[N];
    for(int i=0;i<N;i++){
        cin >> Ns[i];
    }
    stable_sort(Ns,Ns+N);
    
    int M;
    cin >> M;
    int Ms[M];
    for(int i=0;i<M;i++){
        cin >> Ms[i];
    }

    for(int i=0;i<M;i++){
        // int* rightMost = upper_bound(Ns,Ns+N,Ms[i]);
        // int* leftMost = lower_bound(Ns,Ns+N,Ms[i]);
        // cout << rightMost-leftMost << " ";

        int left = 0;
        int right = N-1;
        int center = (left+right)/2;
        int answer = 0;
        int leftMost = 0;
        int rightMost = -1;
        while(right >= left){
            // cout << i<<" "  << 1 << " "<<left << " " << center << " " << right << "\n";
            if((center == 0 || Ms[i] > Ns[center-1])&& Ms[i] == Ns[center]){
                leftMost = center;
                break;
            } else if(Ms[i] > Ns[center]){
                left = center+1;
                center = (left+right)/2;
            } else {
                right = center-1;
                center = (left+right)/2;
            }
        }

        left = 0;
        right = N-1;
        center = (left+right)/2;
        while(right >= left){
            // cout << i << " " << 2<<" " <<left << " " << center << " " << right << "\n";
            if((center == N-1 || Ms[i] < Ns[center+1])&& Ms[i] == Ns[center]){
                rightMost = center;
                break;
            } else if(Ms[i] >= Ns[center]){
                left = center+1;
                center = (left+right)/2;
            } else {
                right = center-1;
                center = (left+right)/2;
            }
        }
        cout << rightMost - leftMost + 1 << " ";
    }
    cout << "\n";
}