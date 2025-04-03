// 백준 문제 : 숫자의 개수

#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int A,B,C;
	cin >> A >> B >> C;
	
	int mul = A * B * C;
	int divideNum = 100000000; // 1억 == 자릿수를 나눌 수 있는 최대값
	while(divideNum > mul){
		divideNum /= 10;
	}
	
	// cout << mul << "\n";
	vector<int> answer(10,0); // 각 숫자가 쓰인 횟수
	while(divideNum != 0){
		int e = mul / divideNum;
		mul %= divideNum;
		// cout << e << " " << divideNum << "\n";
		answer[e] += 1;
		divideNum /= 10;
	}
	
	for(int i=0;i<10;i++){
		cout << answer[i] << "\n";
	}
	
	return 0;
}