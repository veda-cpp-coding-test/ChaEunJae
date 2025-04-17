// 백준 문제 : 카드2

#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	queue<int> qu;
	for(int i=1;i<N+1;i++){
		qu.push(i);
	}
	
	while(qu.size() > 1){
		qu.pop();
		int e = qu.front();
		qu.pop();
		qu.push(e);
	}
	
	cout << qu.front();
}