// 백준 문제 : 제로

#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	int k;
	cin >> k;
	
	stack<int> si;
	for(int i=0;i<k;i++){
		int e;
		cin >> e;
		if(e == 0){
			si.pop();
		} else {
			si.push(e);
		}
	}
	
	long long sum = 0;
	while(!si.empty()) {
		sum += si.top(); si.pop();
	}
	cout << sum;
}