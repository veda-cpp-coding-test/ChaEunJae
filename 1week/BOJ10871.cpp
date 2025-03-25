// 백준 문제 : X보다 작은 수

#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,X;
	cin >> N >> X;
	
	int arr[N];
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	
	for(int i=0;i<N;i++){
		if(X > arr[i]) cout << arr[i] << " ";
	}
}